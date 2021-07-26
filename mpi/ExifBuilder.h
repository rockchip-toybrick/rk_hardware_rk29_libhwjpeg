/*
 * Copyright 2021 Rockchip Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * author: kevin.chen@rock-chips.com
 */

#ifndef __EXIF_BUILDER_H__
#define __EXIF_BUILDER_H__

/* EXIF tags */
typedef enum {
    EXIF_TAG_INTEROPERABILITY_INDEX         = 0x0001,
    EXIF_TAG_INTEROPERABILITY_VERSION       = 0x0002,
    EXIF_TAG_NEW_SUBFILE_TYPE               = 0x00fe,
    EXIF_TAG_IMAGE_WIDTH                    = 0x0100,
    EXIF_TAG_IMAGE_LENGTH                   = 0x0101,
    EXIF_TAG_BITS_PER_SAMPLE                = 0x0102,
    EXIF_TAG_COMPRESSION                    = 0x0103,
    EXIF_TAG_PHOTOMETRIC_INTERPRETATION     = 0x0106,
    EXIF_TAG_FILL_ORDER                     = 0x010a,
    EXIF_TAG_DOCUMENT_NAME                  = 0x010d,
    EXIF_TAG_IMAGE_DESCRIPTION              = 0x010e,
    EXIF_TAG_MAKE                           = 0x010f,
    EXIF_TAG_MODEL                          = 0x0110,
    EXIF_TAG_STRIP_OFFSETS                  = 0x0111,
    EXIF_TAG_ORIENTATION                    = 0x0112,
    EXIF_TAG_SAMPLES_PER_PIXEL              = 0x0115,
    EXIF_TAG_ROWS_PER_STRIP                 = 0x0116,
    EXIF_TAG_STRIP_BYTE_COUNTS              = 0x0117,
    EXIF_TAG_X_RESOLUTION                   = 0x011a,
    EXIF_TAG_Y_RESOLUTION                   = 0x011b,
    EXIF_TAG_PLANAR_CONFIGURATION           = 0x011c,
    EXIF_TAG_RESOLUTION_UNIT                = 0x0128,
    EXIF_TAG_TRANSFER_FUNCTION              = 0x012d,
    EXIF_TAG_SOFTWARE                       = 0x0131,
    EXIF_TAG_DATE_TIME                      = 0x0132,
    EXIF_TAG_ARTIST                         = 0x013b,
    EXIF_TAG_WHITE_POINT                    = 0x013e,
    EXIF_TAG_PRIMARY_CHROMATICITIES         = 0x013f,
    EXIF_TAG_SUB_IFDS                       = 0x014a,
    EXIF_TAG_TRANSFER_RANGE                 = 0x0156,
    EXIF_TAG_JPEG_PROC                      = 0x0200,
    EXIF_TAG_JPEG_INTERCHANGE_FORMAT        = 0x0201,
    EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH = 0x0202,
    EXIF_TAG_YCBCR_COEFFICIENTS             = 0x0211,
    EXIF_TAG_YCBCR_SUB_SAMPLING             = 0x0212,
    EXIF_TAG_YCBCR_POSITIONING              = 0x0213,
    EXIF_TAG_REFERENCE_BLACK_WHITE          = 0x0214,
    EXIF_TAG_XML_PACKET                     = 0x02bc,
    EXIF_TAG_RELATED_IMAGE_FILE_FORMAT      = 0x1000,
    EXIF_TAG_RELATED_IMAGE_WIDTH            = 0x1001,
    EXIF_TAG_RELATED_IMAGE_LENGTH           = 0x1002,
    EXIF_TAG_CFA_REPEAT_PATTERN_DIM         = 0x828d,
    EXIF_TAG_CFA_PATTERN                    = 0x828e,
    EXIF_TAG_BATTERY_LEVEL                  = 0x828f,
    EXIF_TAG_COPYRIGHT                      = 0x8298,
    EXIF_TAG_EXPOSURE_TIME                  = 0x829a,
    EXIF_TAG_FNUMBER                        = 0x829d,
    EXIF_TAG_IPTC_NAA                       = 0x83bb,
    EXIF_TAG_IMAGE_RESOURCES                = 0x8649,
    EXIF_TAG_EXIF_IFD_POINTER               = 0x8769,
    EXIF_TAG_INTER_COLOR_PROFILE            = 0x8773,
    EXIF_TAG_EXPOSURE_PROGRAM               = 0x8822,
    EXIF_TAG_SPECTRAL_SENSITIVITY           = 0x8824,
    EXIF_TAG_GPS_INFO_IFD_POINTER           = 0x8825,
    EXIF_TAG_ISO_SPEED_RATINGS              = 0x8827,
    EXIF_TAG_OECF                           = 0x8828,
    EXIF_TAG_TIME_ZONE_OFFSET               = 0x882a,
    EXIF_TAG_EXIF_VERSION                   = 0x9000,
    EXIF_TAG_DATE_TIME_ORIGINAL             = 0x9003,
    EXIF_TAG_DATE_TIME_DIGITIZED            = 0x9004,
    EXIF_TAG_COMPONENTS_CONFIGURATION       = 0x9101,
    EXIF_TAG_COMPRESSED_BITS_PER_PIXEL      = 0x9102,
    EXIF_TAG_SHUTTER_SPEED_VALUE            = 0x9201,
    EXIF_TAG_APERTURE_VALUE                 = 0x9202,
    EXIF_TAG_BRIGHTNESS_VALUE               = 0x9203,
    EXIF_TAG_EXPOSURE_BIAS_VALUE            = 0x9204,
    EXIF_TAG_MAX_APERTURE_VALUE             = 0x9205,
    EXIF_TAG_SUBJECT_DISTANCE               = 0x9206,
    EXIF_TAG_METERING_MODE                  = 0x9207,
    EXIF_TAG_LIGHT_SOURCE                   = 0x9208,
    EXIF_TAG_FLASH                          = 0x9209,
    EXIF_TAG_FOCAL_LENGTH                   = 0x920a,
    EXIF_TAG_SUBJECT_AREA                   = 0x9214,
    EXIF_TAG_TIFF_EP_STANDARD_ID            = 0x9216,
    EXIF_TAG_MAKER_NOTE                     = 0x927c,
    EXIF_TAG_USER_COMMENT                   = 0x9286,
    EXIF_TAG_SUB_SEC_TIME                   = 0x9290,
    EXIF_TAG_SUB_SEC_TIME_ORIGINAL          = 0x9291,
    EXIF_TAG_SUB_SEC_TIME_DIGITIZED         = 0x9292,
    EXIF_TAG_XP_TITLE                       = 0x9c9b,
    EXIF_TAG_XP_COMMENT                     = 0x9c9c,
    EXIF_TAG_XP_AUTHOR                      = 0x9c9d,
    EXIF_TAG_XP_KEYWORDS                    = 0x9c9e,
    EXIF_TAG_XP_SUBJECT                     = 0x9c9f,
    EXIF_TAG_FLASH_PIX_VERSION              = 0xa000,
    EXIF_TAG_COLOR_SPACE                    = 0xa001,
    EXIF_TAG_PIXEL_X_DIMENSION              = 0xa002,
    EXIF_TAG_PIXEL_Y_DIMENSION              = 0xa003,
    EXIF_TAG_RELATED_SOUND_FILE             = 0xa004,
    EXIF_TAG_INTEROPERABILITY_IFD_POINTER   = 0xa005,
    EXIF_TAG_FLASH_ENERGY                   = 0xa20b,
    EXIF_TAG_SPATIAL_FREQUENCY_RESPONSE     = 0xa20c,
    EXIF_TAG_FOCAL_PLANE_X_RESOLUTION       = 0xa20e,
    EXIF_TAG_FOCAL_PLANE_Y_RESOLUTION       = 0xa20f,
    EXIF_TAG_FOCAL_PLANE_RESOLUTION_UNIT    = 0xa210,
    EXIF_TAG_SUBJECT_LOCATION               = 0xa214,
    EXIF_TAG_EXPOSURE_INDEX                 = 0xa215,
    EXIF_TAG_SENSING_METHOD                 = 0xa217,
    EXIF_TAG_FILE_SOURCE                    = 0xa300,
    EXIF_TAG_SCENE_TYPE                     = 0xa301,
    EXIF_TAG_NEW_CFA_PATTERN                = 0xa302,
    EXIF_TAG_CUSTOM_RENDERED                = 0xa401,
    EXIF_TAG_EXPOSURE_MODE                  = 0xa402,
    EXIF_TAG_WHITE_BALANCE                  = 0xa403,
    EXIF_TAG_DIGITAL_ZOOM_RATIO             = 0xa404,
    EXIF_TAG_FOCAL_LENGTH_IN_35MM_FILM      = 0xa405,
    EXIF_TAG_SCENE_CAPTURE_TYPE             = 0xa406,
    EXIF_TAG_GAIN_CONTROL                   = 0xa407,
    EXIF_TAG_CONTRAST                       = 0xa408,
    EXIF_TAG_SATURATION                     = 0xa409,
    EXIF_TAG_SHARPNESS                      = 0xa40a,
    EXIF_TAG_DEVICE_SETTING_DESCRIPTION     = 0xa40b,
    EXIF_TAG_SUBJECT_DISTANCE_RANGE         = 0xa40c,
    EXIF_TAG_IMAGE_UNIQUE_ID                = 0xa420,
    EXIF_TAG_CAMERA_OWNER_NAME              = 0xa430,
    EXIF_TAG_BODY_SERIAL_NUMBER             = 0xa431,
    EXIF_TAG_LENS_SPECIFICATION             = 0xa432,
    EXIF_TAG_LENS_MAKE                      = 0xa433,
    EXIF_TAG_LENS_MODEL                     = 0xa434,
    EXIF_TAG_LENS_SERIAL_NUMBER             = 0xa435,
    EXIF_TAG_GAMMA                          = 0xa500,
    EXIF_TAG_PRINT_IMAGE_MATCHING           = 0xc4a5,
    EXIF_TAG_PADDING                        = 0xea1c,

    /* GPS_INFO_TAG */
    /* GPS tags overlap with above ones. */
    EXIF_TAG_GPS_VERSION_ID                 = 0x0000,
    EXIF_TAG_GPS_LATITUDE_REF               = 0x0001, /* INTEROPERABILITY_INDEX */
    EXIF_TAG_GPS_LATITUDE                   = 0x0002, /* INTEROPERABILITY_VERSION */
    EXIF_TAG_GPS_LONGITUDE_REF              = 0x0003,
    EXIF_TAG_GPS_LONGITUDE                  = 0x0004,
    EXIF_TAG_GPS_ALTITUDE_REF               = 0x0005,
    EXIF_TAG_GPS_ALTITUDE                   = 0x0006,
    EXIF_TAG_GPS_TIME_STAMP                 = 0x0007,
    EXIF_TAG_GPS_SATELLITES                 = 0x0008,
    EXIF_TAG_GPS_STATUS                     = 0x0009,
    EXIF_TAG_GPS_MEASURE_MODE               = 0x000a,
    EXIF_TAG_GPS_DOP                        = 0x000b,
    EXIF_TAG_GPS_SPEED_REF                  = 0x000c,
    EXIF_TAG_GPS_SPEED                      = 0x000d,
    EXIF_TAG_GPS_TRACK_REF                  = 0x000e,
    EXIF_TAG_GPS_TRACK                      = 0x000f,
    EXIF_TAG_GPS_IMG_DIRECTION_REF          = 0x0010,
    EXIF_TAG_GPS_IMG_DIRECTION              = 0x0011,
    EXIF_TAG_GPS_MAP_DATUM                  = 0x0012,
    EXIF_TAG_GPS_DEST_LATITUDE_REF          = 0x0013,
    EXIF_TAG_GPS_DEST_LATITUDE              = 0x0014,
    EXIF_TAG_GPS_DEST_LONGITUDE_REF         = 0x0015,
    EXIF_TAG_GPS_DEST_LONGITUDE             = 0x0016,
    EXIF_TAG_GPS_DEST_BEARING_REF           = 0x0017,
    EXIF_TAG_GPS_DEST_BEARING               = 0x0018,
    EXIF_TAG_GPS_DEST_DISTANCE_REF          = 0x0019,
    EXIF_TAG_GPS_DEST_DISTANCE              = 0x001a,
    EXIF_TAG_GPS_PROCESSING_METHOD          = 0x001b,
    EXIF_TAG_GPS_AREA_INFORMATION           = 0x001c,
    EXIF_TAG_GPS_DATE_STAMP                 = 0x001d,
    EXIF_TAG_GPS_DIFFERENTIAL               = 0x001e,
    EXIF_TAG_GPS_H_POSITIONING_ERROR        = 0x001f,
} ExifTag;

/* EXIF tag data formats */
typedef enum {
    EXIF_FORMAT_BYTE       =  1,
    EXIF_FORMAT_ASCII      =  2,
    EXIF_FORMAT_SHORT      =  3,
    EXIF_FORMAT_LONG       =  4,
    EXIF_FORMAT_RATIONAL   =  5,
    EXIF_FORMAT_SBYTE      =  6,
    EXIF_FORMAT_UNDEFINED  =  7,
    EXIF_FORMAT_SSHORT     =  8,
    EXIF_FORMAT_SLONG      =  9,
    EXIF_FORMAT_SRATIONAL  = 10,
    EXIF_FORMAT_FLOAT      = 11,
    EXIF_FORMAT_DOUBLE     = 12,
} ExifFormat;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} ExifRational;

/* Which byte order to use */
typedef enum {
    /* Big-endian byte order */
    EXIF_BYTE_ORDER_MOTOROLA,
    /* Little-endian byte order */
    EXIF_BYTE_ORDER_INTEL,
} ExifByteOrder;

/* Possible EXIF Image File Directories */
typedef enum {
    EXIF_IFD_0 = 0,                /*!< */
    EXIF_IFD_1,                    /*!< */
    EXIF_IFD_EXIF,                 /*!< */
    EXIF_IFD_GPS,                  /*!< */
    EXIF_IFD_INTEROPERABILITY,     /*!< */
    EXIF_IFD_COUNT,                /*!< Not a real value, just (max_value + 1). */
} ExifIfd;

/* Data found in one EXIF tag */
typedef struct {
    /* EXIF tag for this entry */
    ExifTag tag;

    /* Type of data in this entry */
    ExifFormat format;

    /* Number of elements in the array, if this is an array entry.
       Contains 1 for non-array data types. */
    unsigned long components;

    /* Pointer to the raw EXIF data for this entry. It is allocated
       by #exif_entry_initialize and is NULL beforehand. Data contained
       here may be manipulated using the functions in exif-utils.h */
    unsigned char *data;
} ExifEntry;

typedef struct {
    ExifEntry entries[40];
    int entry_count;
} ExifContent;

/* Represents the entire EXIF data found in an image */
typedef struct {
    /* Data for each IFD */
    ExifContent ifd[EXIF_IFD_COUNT];
    /* Pointer to thumbnail image, or NULL if not available */
    unsigned char *thumb_data;
    /* Number of bytes in thumbnail image at thumbData */
    unsigned int thumb_size;

    ExifByteOrder order;
} ExifData;

void exif_set_rational(unsigned char *b, ExifByteOrder order, ExifRational value);
void exif_set_short(unsigned char *b, ExifByteOrder order, uint16_t value);
void exif_set_long(unsigned char *b, ExifByteOrder order, uint32_t value);

void exif_setup_entry(ExifEntry *entry, ExifTag tag, ExifFormat format,
                      unsigned long components, char *data);
void exif_setup_rational_entry(ExifEntry *entry, ExifTag tag,
                               ExifFormat format, unsigned long components,
                               ExifByteOrder order, ExifRational *rat);
void exif_setup_short_entry(ExifEntry *entry, ExifTag tag, ExifFormat format,
                            unsigned long components, ExifByteOrder order,
                            uint16_t value);
void exif_setup_long_entry(ExifEntry *entry, ExifTag tag, ExifFormat format,
                           unsigned long components, ExifByteOrder order,
                           uint32_t value);

void exif_release_entry(ExifEntry *entry);

/*
 * Store raw EXIF data representing the #ExifData into a memory buffer.
 *
 * param[in] edata - EXIF data
 * param[out] buf  - pointer to buffer pointer containing raw EXIF data.
 * param[out] len  - pointer to hold the buf number bytes, set to 0 on error
 */
bool exif_general_build(ExifData *edata, unsigned char **buf, int *len);

#endif  // __EXIF_BUILDER_H__
