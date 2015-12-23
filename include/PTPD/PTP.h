#ifndef __RAILWAY_PTP_H__
#define __RAILWAY_PTP_H__

#define PTP_OPERATION_GET_DEVICE_INFO                       0x1001
#define PTP_OPERATION_OPEN_SESSION                          0x1002
#define PTP_OPERATION_CLOSE_SESSION                         0x1003
#define PTP_OPERATION_GET_STORAGE_IDS                       0x1004
#define PTP_OPERATION_GET_STORAGE_INFO                      0x1005
#define PTP_OPERATION_GET_NUM_OBJECTS                       0x1006
#define PTP_OPERATION_GET_OBJECT_HANDLES                    0x1007
#define PTP_OPERATION_GET_OBJECT_INFO                       0x1008
#define PTP_OPERATION_GET_OBJECT                            0x1009
#define PTP_OPERATION_GET_THUMB                             0x100A
#define PTP_OPERATION_DELETE_OBJECT                         0x100B
#define PTP_OPERATION_SEND_OBJECT_INFO                      0x100C
#define PTP_OPERATION_SEND_OBJECT                           0x100D
#define PTP_OPERATION_INITIATE_CAPTURE                      0x100E
#define PTP_OPERATION_FORMAT_STORE                          0x100F
#define PTP_OPERATION_RESET_DEVICE                          0x1010
#define PTP_OPERATION_SELF_TEST                             0x1011
#define PTP_OPERATION_SET_OBJECT_PROTECTION                 0x1012
#define PTP_OPERATION_POWER_DOWN                            0x1013
#define PTP_OPERATION_GET_DEVICE_PROP_DESC                  0x1014
#define PTP_OPERATION_GET_DEVICE_PROP_VALUE                 0x1015
#define PTP_OPERATION_SET_DEVICE_PROP_VALUE                 0x1016
#define PTP_OPERATION_RESET_DEVICE_PROP_VALUE               0x1017
#define PTP_OPERATION_TERMINATE_OPEN_CAPTURE                0x1018
#define PTP_OPERATION_MOVE_OBJECT                           0x1019
#define PTP_OPERATION_COPY_OBJECT                           0x101A
#define PTP_OPERATION_GET_PARTIAL_OBJECT                    0x101B
#define PTP_OPERATION_INITIATE_OPEN_CAPTURE                 0x101C
#define PTP_OPERATION_GET_OBJECT_PROPS_SUPPORTED            0x9801
#define PTP_OPERATION_GET_OBJECT_PROP_DESC                  0x9802
#define PTP_OPERATION_GET_OBJECT_PROP_VALUE                 0x9803
#define PTP_OPERATION_SET_OBJECT_PROP_VALUE                 0x9804
#define PTP_OPERATION_GET_OBJECT_PROP_LIST                  0x9805
#define PTP_OPERATION_SET_OBJECT_PROP_LIST                  0x9806
#define PTP_OPERATION_GET_INTERDEPENDENT_PROP_DESC          0x9807
#define PTP_OPERATION_SEND_OBJECT_PROP_LIST                 0x9808
#define PTP_OPERATION_GET_OBJECT_REFERENCES                 0x9810
#define PTP_OPERATION_SET_OBJECT_REFERENCES                 0x9811
#define PTP_OPERATION_SKIP                                  0x9820
#define	PTP_OPERATION_GET_PARTIAL_OBJECT_64	        		0x95C1
#define PTP_OPERATION_SEND_PARTIAL_OBJECT          			0x95C2
#define PTP_OPERATION_TRUNCATE_OBJECT              			0x95C3
#define PTP_OPERATION_BEGIN_EDIT_OBJECT            			0x95C4
#define PTP_OPERATION_END_EDIT_OBJECT              			0x95C5
	
	
#define PTP_RESPONSE_UNDEFINED                                  0x2000
#define PTP_RESPONSE_OK                                         0x2001
#define PTP_RESPONSE_GENERAL_ERROR                              0x2002
#define PTP_RESPONSE_SESSION_NOT_OPEN                           0x2003
#define PTP_RESPONSE_INVALID_TRANSACTION_ID                     0x2004
#define PTP_RESPONSE_OPERATION_NOT_SUPPORTED                    0x2005
#define PTP_RESPONSE_PARAMETER_NOT_SUPPORTED                    0x2006
#define PTP_RESPONSE_INCOMPLETE_TRANSFER                        0x2007
#define PTP_RESPONSE_INVALID_STORAGE_ID                         0x2008
#define PTP_RESPONSE_INVALID_OBJECT_HANDLE                      0x2009
#define PTP_RESPONSE_DEVICE_PROP_NOT_SUPPORTED                  0x200A
#define PTP_RESPONSE_INVALID_OBJECT_FORMAT_CODE                 0x200B
#define PTP_RESPONSE_STORAGE_FULL                               0x200C
#define PTP_RESPONSE_OBJECT_WRITE_PROTECTED                     0x200D
#define PTP_RESPONSE_STORE_READ_ONLY                            0x200E
#define PTP_RESPONSE_ACCESS_DENIED                              0x200F
#define PTP_RESPONSE_NO_THUMBNAIL_PRESENT                       0x2010
#define PTP_RESPONSE_SELF_TEST_FAILED                           0x2011
#define PTP_RESPONSE_PARTIAL_DELETION                           0x2012
#define PTP_RESPONSE_STORE_NOT_AVAILABLE                        0x2013
#define PTP_RESPONSE_SPECIFICATION_BY_FORMAT_UNSUPPORTED        0x2014
#define PTP_RESPONSE_NO_VALID_OBJECT_INFO                       0x2015
#define PTP_RESPONSE_INVALID_CODE_FORMAT                        0x2016
#define PTP_RESPONSE_UNKNOWN_VENDOR_CODE                        0x2017
#define PTP_RESPONSE_CAPTURE_ALREADY_TERMINATED                 0x2018
#define PTP_RESPONSE_DEVICE_BUSY                                0x2019
#define PTP_RESPONSE_INVALID_PARENT_OBJECT                      0x201A
#define PTP_RESPONSE_INVALID_DEVICE_PROP_FORMAT                 0x201B
#define PTP_RESPONSE_INVALID_DEVICE_PROP_VALUE                  0x201C
#define PTP_RESPONSE_INVALID_PARAMETER                          0x201D
#define PTP_RESPONSE_SESSION_ALREADY_OPEN                       0x201E
#define PTP_RESPONSE_TRANSACTION_CANCELLED                      0x201F
#define PTP_RESPONSE_SPECIFICATION_OF_DESTINATION_UNSUPPORTED   0x2020
#define PTP_RESPONSE_INVALID_OBJECT_PROP_CODE                   0xA801
#define PTP_RESPONSE_INVALID_OBJECT_PROP_FORMAT                 0xA802
#define PTP_RESPONSE_INVALID_OBJECT_PROP_VALUE                  0xA803
#define PTP_RESPONSE_INVALID_OBJECT_REFERENCE                   0xA804
#define PTP_RESPONSE_GROUP_NOT_SUPPORTED                        0xA805
#define PTP_RESPONSE_INVALID_DATASET                            0xA806
#define PTP_RESPONSE_SPECIFICATION_BY_GROUP_UNSUPPORTED         0xA807
#define PTP_RESPONSE_SPECIFICATION_BY_DEPTH_UNSUPPORTED         0xA808
#define PTP_RESPONSE_OBJECT_TOO_LARGE                           0xA809
#define PTP_RESPONSE_OBJECT_PROP_NOT_SUPPORTED                  0xA80A

#define PTP_EVENT_UNDEFINED                         0x4000
#define PTP_EVENT_CANCEL_TRANSACTION                0x4001
#define PTP_EVENT_OBJECT_ADDED                      0x4002
#define PTP_EVENT_OBJECT_REMOVED                    0x4003
#define PTP_EVENT_STORE_ADDED                       0x4004
#define PTP_EVENT_STORE_REMOVED                     0x4005
#define PTP_EVENT_DEVICE_PROP_CHANGED               0x4006
#define PTP_EVENT_OBJECT_INFO_CHANGED               0x4007
#define PTP_EVENT_DEVICE_INFO_CHANGED               0x4008
#define PTP_EVENT_REQUEST_OBJECT_TRANSFER           0x4009
#define PTP_EVENT_STORE_FULL                        0x400A
#define PTP_EVENT_DEVICE_RESET                      0x400B
#define PTP_EVENT_STORAGE_INFO_CHANGED              0x400C
#define PTP_EVENT_CAPTURE_COMPLETE                  0x400D
#define PTP_EVENT_UNREPORTED_STATUS                 0x400E
#define PTP_EVENT_OBJECT_PROP_CHANGED               0xC801
#define PTP_EVENT_OBJECT_PROP_DESC_CHANGED          0xC802
#define PTP_EVENT_OBJECT_REFERENCES_CHANGED         0xC803

#define PTP_FORMAT_UNDEFINED                            0x3000   // Undefined object
#define PTP_FORMAT_ASSOCIATION                          0x3001   // Association (for example, a folder)
#define PTP_FORMAT_SCRIPT                               0x3002   // Device model-specific script
#define PTP_FORMAT_EXECUTABLE                           0x3003   // Device model-specific binary executable
#define PTP_FORMAT_TEXT                                 0x3004   // Text file
#define PTP_FORMAT_HTML                                 0x3005   // Hypertext Markup Language file (text)
#define PTP_FORMAT_DPOF                                 0x3006   // Digital Print Order Format file (text)
#define PTP_FORMAT_AIFF                                 0x3007   // Audio clip
#define PTP_FORMAT_WAV                                  0x3008   // Audio clip
#define PTP_FORMAT_MP3                                  0x3009   // Audio clip
#define PTP_FORMAT_AVI                                  0x300A   // Video clip
#define PTP_FORMAT_MPEG                                 0x300B   // Video clip
#define PTP_FORMAT_ASF                                  0x300C   // Microsoft Advanced Streaming Format (video)
#define PTP_FORMAT_DEFINED                              0x3800   // Unknown image object
#define PTP_FORMAT_EXIF_JPEG                            0x3801   // Exchangeable File Format, JEIDA standard
#define PTP_FORMAT_TIFF_EP                              0x3802   // Tag Image File Format for Electronic Photography
#define PTP_FORMAT_FLASHPIX                             0x3803   // Structured Storage Image Format
#define PTP_FORMAT_BMP                                  0x3804   // Microsoft Windows Bitmap file
#define PTP_FORMAT_CIFF                                 0x3805   // Canon Camera Image File Format
#define PTP_FORMAT_GIF                                  0x3807   // Graphics Interchange Format
#define PTP_FORMAT_JFIF                                 0x3808   // JPEG File Interchange Format
#define PTP_FORMAT_CD                                   0x3809   // PhotoCD Image Pac
#define PTP_FORMAT_PICT                                 0x380A   // Quickdraw Image Format
#define PTP_FORMAT_PNG                                  0x380B   // Portable Network Graphics
#define PTP_FORMAT_TIFF                                 0x380D   // Tag Image File Format
#define PTP_FORMAT_TIFF_IT                              0x380E   // Tag Image File Format for Information Technology (graphic arts)
#define PTP_FORMAT_JP2                                  0x380F   // JPEG2000 Baseline File Format
#define PTP_FORMAT_JPX                                  0x3810   // JPEG2000 Extended File Format
#define PTP_FORMAT_UNDEFINED_FIRMWARE                   0xB802
#define PTP_FORMAT_WINDOWS_IMAGE_FORMAT                 0xB881
#define PTP_FORMAT_UNDEFINED_AUDIO                      0xB900
#define PTP_FORMAT_WMA                                  0xB901
#define PTP_FORMAT_OGG                                  0xB902
#define PTP_FORMAT_AAC                                  0xB903
#define PTP_FORMAT_AUDIBLE                              0xB904
#define PTP_FORMAT_FLAC                                 0xB906
#define PTP_FORMAT_UNDEFINED_VIDEO                      0xB980
#define PTP_FORMAT_WMV                                  0xB981
#define PTP_FORMAT_MP4_CONTAINER                        0xB982  // ISO 14496-1
#define PTP_FORMAT_MP2                                  0xB983
#define PTP_FORMAT_3GP_CONTAINER                        0xB984  // 3GPP file format. Details: http://www.3gpp.org/ftp/Specs/html-info/26244.htm (page title - \u201cTransparent end-to-end packet switched streaming service, 3GPP file format\u201d).
#define PTP_FORMAT_UNDEFINED_COLLECTION                 0xBA00
#define PTP_FORMAT_ABSTRACT_MULTIMEDIA_ALBUM            0xBA01
#define PTP_FORMAT_ABSTRACT_IMAGE_ALBUM                 0xBA02
#define PTP_FORMAT_ABSTRACT_AUDIO_ALBUM                 0xBA03
#define PTP_FORMAT_ABSTRACT_VIDEO_ALBUM                 0xBA04
#define PTP_FORMAT_ABSTRACT_AV_PLAYLIST                 0xBA05
#define PTP_FORMAT_ABSTRACT_CONTACT_GROUP               0xBA06
#define PTP_FORMAT_ABSTRACT_MESSAGE_FOLDER              0xBA07
#define PTP_FORMAT_ABSTRACT_CHAPTERED_PRODUCTION        0xBA08
#define PTP_FORMAT_ABSTRACT_AUDIO_PLAYLIST              0xBA09
#define PTP_FORMAT_ABSTRACT_VIDEO_PLAYLIST              0xBA0A
#define PTP_FORMAT_ABSTRACT_MEDIACAST                   0xBA0B // For use with mediacasts; references multimedia enclosures of RSS feeds or episodic content
#define PTP_FORMAT_WPL_PLAYLIST                         0xBA10
#define PTP_FORMAT_M3U_PLAYLIST                         0xBA11
#define PTP_FORMAT_MPL_PLAYLIST                         0xBA12
#define PTP_FORMAT_ASX_PLAYLIST                         0xBA13
#define PTP_FORMAT_PLS_PLAYLIST                         0xBA14
#define PTP_FORMAT_UNDEFINED_DOCUMENT                   0xBA80
#define PTP_FORMAT_ABSTRACT_DOCUMENT                    0xBA81
#define PTP_FORMAT_XML_DOCUMENT                         0xBA82
#define PTP_FORMAT_MS_WORD_DOCUMENT                     0xBA83
#define PTP_FORMAT_MHT_COMPILED_HTML_DOCUMENT           0xBA84
#define PTP_FORMAT_MS_EXCEL_SPREADSHEET                 0xBA85
#define PTP_FORMAT_MS_POWERPOINT_PRESENTATION           0xBA86
#define PTP_FORMAT_UNDEFINED_MESSAGE                    0xBB00
#define PTP_FORMAT_ABSTRACT_MESSSAGE                    0xBB01
#define PTP_FORMAT_UNDEFINED_CONTACT                    0xBB80
#define PTP_FORMAT_ABSTRACT_CONTACT                     0xBB81
#define PTP_FORMAT_VCARD_2                              0xBB82
#define PTP_FORMAT_WINDOWS_EXECUTABLE					0xBE80

#define PTP_RESPONSE_UNDEFINED                                  0x2000
#define PTP_RESPONSE_OK                                         0x2001
#define PTP_RESPONSE_GENERAL_ERROR                              0x2002
#define PTP_RESPONSE_SESSION_NOT_OPEN                           0x2003
#define PTP_RESPONSE_INVALID_TRANSACTION_ID                     0x2004
#define PTP_RESPONSE_OPERATION_NOT_SUPPORTED                    0x2005
#define PTP_RESPONSE_PARAMETER_NOT_SUPPORTED                    0x2006
#define PTP_RESPONSE_INCOMPLETE_TRANSFER                        0x2007
#define PTP_RESPONSE_INVALID_STORAGE_ID                         0x2008
#define PTP_RESPONSE_INVALID_OBJECT_HANDLE                      0x2009
#define PTP_RESPONSE_DEVICE_PROP_NOT_SUPPORTED                  0x200A
#define PTP_RESPONSE_INVALID_OBJECT_FORMAT_CODE                 0x200B
#define PTP_RESPONSE_STORAGE_FULL                               0x200C
#define PTP_RESPONSE_OBJECT_WRITE_PROTECTED                     0x200D
#define PTP_RESPONSE_STORE_READ_ONLY                            0x200E
#define PTP_RESPONSE_ACCESS_DENIED                              0x200F
#define PTP_RESPONSE_NO_THUMBNAIL_PRESENT                       0x2010
#define PTP_RESPONSE_SELF_TEST_FAILED                           0x2011
#define PTP_RESPONSE_PARTIAL_DELETION                           0x2012
#define PTP_RESPONSE_STORE_NOT_AVAILABLE                        0x2013
#define PTP_RESPONSE_SPECIFICATION_BY_FORMAT_UNSUPPORTED        0x2014
#define PTP_RESPONSE_NO_VALID_OBJECT_INFO                       0x2015
#define PTP_RESPONSE_INVALID_CODE_FORMAT                        0x2016
#define PTP_RESPONSE_UNKNOWN_VENDOR_CODE                        0x2017
#define PTP_RESPONSE_CAPTURE_ALREADY_TERMINATED                 0x2018
#define PTP_RESPONSE_DEVICE_BUSY                                0x2019
#define PTP_RESPONSE_INVALID_PARENT_OBJECT                      0x201A
#define PTP_RESPONSE_INVALID_DEVICE_PROP_FORMAT                 0x201B
#define PTP_RESPONSE_INVALID_DEVICE_PROP_VALUE                  0x201C
#define PTP_RESPONSE_INVALID_PARAMETER                          0x201D
#define PTP_RESPONSE_SESSION_ALREADY_OPEN                       0x201E
#define PTP_RESPONSE_TRANSACTION_CANCELLED                      0x201F
#define PTP_RESPONSE_SPECIFICATION_OF_DESTINATION_UNSUPPORTED   0x2020
#define PTP_RESPONSE_INVALID_OBJECT_PROP_CODE                   0xA801
#define PTP_RESPONSE_INVALID_OBJECT_PROP_FORMAT                 0xA802
#define PTP_RESPONSE_INVALID_OBJECT_PROP_VALUE                  0xA803
#define PTP_RESPONSE_INVALID_OBJECT_REFERENCE                   0xA804
#define PTP_RESPONSE_GROUP_NOT_SUPPORTED                        0xA805
#define PTP_RESPONSE_INVALID_DATASET                            0xA806
#define PTP_RESPONSE_SPECIFICATION_BY_GROUP_UNSUPPORTED         0xA807
#define PTP_RESPONSE_SPECIFICATION_BY_DEPTH_UNSUPPORTED         0xA808
#define PTP_RESPONSE_OBJECT_TOO_LARGE                           0xA809
#define PTP_RESPONSE_OBJECT_PROP_NOT_SUPPORTED                  0xA80A

#endif /* __RAILWAY_PTP_H__ */