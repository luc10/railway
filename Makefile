include theos/makefiles/common.mk

TWEAK_NAME = Railway
Railway_FILES = 	source/RWMarkStart.xm			\
				Tweak.xm						\
				source/RWFile.xm				\
				source/RWTime.xm				\
				source/RWString.xm			\
				source/RWPList.xm				\
				source/RWContainer.xm			\
				source/RWFolder.xm			\
				source/RWStorage.xm			\
				source/RWRecordings.xm			\
				source/RWITunesLibrary.xm		\
				source/RWDownloads.xm			\
				source/RWTransport.xm			\
				source/RWResponder.xm			\
				source/RWUIDevice.xm			\
				source/RWNotificationCenter.xm	\
				source/RWBase64.xm			\
				source/RWBlowfish.xm			\
				source/RWMD2.xm				\
				source/RWCipher.xm			\
				source/RWSettings.xm			\
				source/RWGlobals.xm			\
				source/RWVirtualCamera.xm		\
				source/RWMarkEnd.xm
				
Railway_LDFLAGS = -lsqlite3 -llockdown -ldl
Railway_CFLAGS = -fvisibility=hidden -Iinclude/
Railway_FRAMEWORKS = UIKit
Railway_PRIVATE_FRAMEWORKS = AppSupport

SUBPROJECTS = Railway

include $(THEOS_MAKE_PATH)/tweak.mk
include $(THEOS_MAKE_PATH)/aggregate.mk
