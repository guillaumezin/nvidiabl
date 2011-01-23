TARGET 		:= nvidiabl
VERSION		:= 0.61
RELEASE_NAME	:= $(TARGET)-$(VERSION)

KVER		:= $(shell uname -r)
KDIR		?= /lib/modules/$(KVER)/build
PWD		:= $(shell pwd)
LOC		:= /kernel/drivers/video/backlight
MODPATH		:= $(DESTDIR)/lib/modules/$(KVER)$(LOC)
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
	find . \( -name dkms.conf -o -name '.tmp*' -o -name '.*.cmd' -o -name '*.symvers' -o -name '*.order' -o -name '*.markers' -o -name '*.mod.c' -o -name '*.ko' -o -name '*.o' \) -print0 | xargs -0 rm -Rf

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

test: modules
	@sudo rmmod $(TARGET)
	@sudo insmod ./$(TARGET).ko

dkms-conf:
	@echo "DEST_MODULE_LOCATION[0]=\"$(LOC)\"" > dkms.conf
	@echo "PACKAGE_NAME=\"$(TARGET)\"" >> dkms.conf
	@echo "PACKAGE_VERSION=\"$(VERSION)\"" >> dkms.conf
	@echo "CLEAN=\"make -C \$${kernel_source_dir} SUBDIRS=\$${dkms_tree}/\$${PACKAGE_NAME}/\$${PACKAGE_VERSION}/build clean\"" >> dkms.conf
	@echo "BUILT_MODULE_NAME[0]=\"\$${PACKAGE_NAME}\"" >> dkms.conf
	@echo "MAKE[0]=\"make -C \$${kernel_source_dir} SUBDIRS=\$${dkms_tree}/\$${PACKAGE_NAME}/\$${PACKAGE_VERSION}/build modules\"" >> dkms.conf
	@echo "REMAKE_INITRD=\"no\"" >> dkms.conf
	@echo "AUTOINSTALL=\"yes\"" >> dkms.conf

dkms-remove:
	sudo dkms remove -m $(TARGET) -v $(VERSION) --all
	sudo rm -rf /usr/src/$(TARGET)-$(VERSION)

dkms-install: dkms-conf
	sudo mkdir /usr/src/$(TARGET)-$(VERSION)
	sudo cp -f * /usr/src/$(TARGET)-$(VERSION)
	sudo dkms add build install -m $(TARGET) -v $(VERSION)

dkms-release:
	sudo dkms mkdeb mktarball --source-only -m $(TARGET) -v $(VERSION)
	git commit *
	git push
	git tag -f v$(VERSION)
	git push --tags
