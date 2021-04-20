/*
 * communicate_payload.h
 *
 *  Created on: Mar 2, 2020
 *      Author: Dang Nam
 */

#ifndef INC_COMMUNICATE_PAYLOAD_H_
#define INC_COMMUNICATE_PAYLOAD_H_

#include "common_def.h"
#include "main.h"

#define START_CHAR		    (0x28)
#define END_CHAR		    (0x29)
#define ADD_CHAR		    (0x7D)
#define XOR_CHAR		    (0x02)
#define RECEIVE_END		    "})"
#define RECEIVE_END_LENGTH	2

#define MIN_MESSAGE_LENGHT	(4)

uint8_t backup_available;
uint16_t backup_length;

int32_t	packPayload		(uint8_t *input_buff, uint8_t *output_buff, int32_t len);
int32_t	unPackPayload	(uint8_t *message_buff, int32_t in_lenght, uint8_t*data_packet);


#endif /* INC_COMMUNICATE_PAYLOAD_H_ */
