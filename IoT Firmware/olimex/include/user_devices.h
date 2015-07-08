#ifndef __USER_DEVICES_H__
	#define __USER_DEVICES_H__
	
	#define DEVICES_URL      "/devices"
	
	typedef enum {
		NATIVE = 0,
		UART,
		I2C,
		SPI
	} device_type;
	
	typedef enum {
		UART_NONE   = 0,
		UART_RFID   = 1,
		UART_FINGER = 2
	} device_uart;
	
	typedef void (*void_func)();
	
	typedef struct _device_description_ {
		device_type type;
		char *url;
		
		uint8 id;
		
		void_func init;
		
		STAILQ_ENTRY(_device_description_) entries;
	} device_description;
	
	void  device_register(device_type type, uint8 id, char *url, void_func init);
	char *device_find_url(device_type type, uint8 id);
	
	void  devices_init();
	
	void devices_handler(
		struct espconn *pConnection, 
		request_method method, 
		char *url, 
		char *data, 
		uint16 data_len, 
		uint32 content_len, 
		char *response,
		uint16 response_len
	);
#endif