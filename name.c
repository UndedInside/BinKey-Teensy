#include <usb_names.h>

#define MANUFACTURER_NAME                                 \
  {                                                       \
    'U', 'n', 'd', 'e', 'd', 'I', 'n', 's', 'i', 'd', 'e' \
  }
#define MANUFACTURER_NAME_LEN 11

#define PRODUCT_NAME                  \
  {                                   \
    'B', 'i', 'n', 'K', 'e', 'y', 's' \
  }
#define PRODUCT_NAME_LEN 7

#define SERIAL_NUMBER       \
  {                         \
    'A', 'l', 'p', 'h', 'a' \
  }
#define SERIAL_NUMBER_LEN 5

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
  2 + MANUFACTURER_NAME_LEN * 2,
  3,
  MANUFACTURER_NAME};

struct usb_string_descriptor_struct usb_string_product_name = {
  2 + PRODUCT_NAME_LEN * 2,
  3,
  PRODUCT_NAME};

struct usb_string_descriptor_struct usb_string_serial_number = {
  2 + SERIAL_NUMBER_LEN * 2,
  3,
  SERIAL_NUMBER};
