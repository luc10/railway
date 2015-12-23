include theos/makefiles/common.mk

BUNDLE_NAME = Railway
Railway_FILES = 	Railway.mm				\
				../source/RWPList.xm		\
				../source/RWUIDevice.xm
				
Railway_CFLAGS 			= -I../include
Railway_LDFLAGS 			= -llockdown -ldl
Railway_INSTALL_PATH 		= /Library/PreferenceBundles
Railway_FRAMEWORKS 		= UIKit Foundation
Railway_PRIVATE_FRAMEWORKS	= Preferences

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/Railway.plist$(ECHO_END)
