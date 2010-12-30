TARGET 		:= nvidiabl
VERSION		:= 0.57
RELEASE_NAME	:= $(TARGET)-$(VERSION)

KVER		:= $(shell uname -r)
KDIR		?= /lib/modules/$(KVER)/build
PWD		:= $(shell pwd)
MODPATH		:= $(DESTDIR)/lib/modules/$(KVER)/kernel/drivers/video/backlight
INCPATH		:= $(DESTDIR)/lib/modules/$(KVER)/include

OBJS 		:= nvidiabl-module.o nvidiabl-models.o
obj-m 		+= $(TARGET).o
$(TARGET)-objs	:= $(OBJS)

# Comment/uncomment to enable/disable debugging
DEBUG = y

EXTRA_CFLAGS = 

ifeq ($(DEBUG),y)
EXTRA_CFLAGS += -DNVIDIA_BL_DEBUG
endif

EXTRA_CFLAGS += -DNVIDIA_BL_VERSION=$(VERSION) \
		 -I$(M) \
		 -I/lib/modules/$(KVER)/include

default: modules

modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

install: $(TARGET).ko
	install -d $(MODPATH)
	install -m 644 -c $(TARGET).ko $(MODPATH)
	/sbin/depmod -a

uninstall:
	rm -f $(MODPATH)/$(TARGET).ko
	/sbin/depmod -a

clean:
	find . \( -name '.tmp*' -o -name '.*.cmd' -o -name '*.symvers' -o -name '*.order' -o -name '*.markers' -o -name '*.mod.c' -o -name '*.ko' -o -name '*.o' \) -print0 | xargs -0 rm -Rf

#depend .depend dep:
#	$(CC) $(CFLAGS) -M *.c > .depend
#
#ifeq (.depend,$(wildcard .depend))
#include .depend
#endif

DISTFILES =  $(shell find . \( -not -name '.' \) -print | grep -v "\.tar\.bz2" | grep -v "\/\." )
DISTDIR = $(RELEASE_NAME)

release: clean
	@rm -rf $(DISTDIR)
	@mkdir $(DISTDIR)
	@chmod 777 $(DISTDIR)
	@for file in $(DISTFILES); do                   \
                if test -d $$file; then                 \
                        mkdir $(DISTDIR)/$$file;        \
                else                                    \
                        cp -p $$file $(DISTDIR)/$$file; \
                fi;                                     \
        done
	@tar -c $(DISTDIR) | bzip2 -9 > $(RELEASE_NAME).tar.bz2
	@rm -rf $(DISTDIR)
