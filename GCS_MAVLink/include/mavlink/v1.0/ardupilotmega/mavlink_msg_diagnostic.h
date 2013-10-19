// MESSAGE DIAGNOSTIC PACKING

#define MAVLINK_MSG_ID_DIAGNOSTIC 204

typedef struct __mavlink_diagnostic_t
{
 float val1; ///< First diagnostic value.
 float val2; ///< Second diagnostic value.
 float val3; ///< Third diagnostic value.
 float val4; ///< Fourth diagnostic value.
 float val5; ///< Fifth diagnostic value.
} mavlink_diagnostic_t;

#define MAVLINK_MSG_ID_DIAGNOSTIC_LEN 20
#define MAVLINK_MSG_ID_204_LEN 20



#define MAVLINK_MESSAGE_INFO_DIAGNOSTIC { \
	"DIAGNOSTIC", \
	5, \
	{  { "val1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_diagnostic_t, val1) }, \
         { "val2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_diagnostic_t, val2) }, \
         { "val3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_diagnostic_t, val3) }, \
         { "val4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_diagnostic_t, val4) }, \
         { "val5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_diagnostic_t, val5) }, \
         } \
}


/**
 * @brief Pack a diagnostic message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param val1 First diagnostic value.
 * @param val2 Second diagnostic value.
 * @param val3 Third diagnostic value.
 * @param val4 Fourth diagnostic value.
 * @param val5 Fifth diagnostic value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_diagnostic_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float val1, float val2, float val3, float val4, float val5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[20];
	_mav_put_float(buf, 0, val1);
	_mav_put_float(buf, 4, val2);
	_mav_put_float(buf, 8, val3);
	_mav_put_float(buf, 12, val4);
	_mav_put_float(buf, 16, val5);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 20);
#else
	mavlink_diagnostic_t packet;
	packet.val1 = val1;
	packet.val2 = val2;
	packet.val3 = val3;
	packet.val4 = val4;
	packet.val5 = val5;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 20);
#endif

	msg->msgid = MAVLINK_MSG_ID_DIAGNOSTIC;
	return mavlink_finalize_message(msg, system_id, component_id, 20, 150);
}

/**
 * @brief Pack a diagnostic message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param val1 First diagnostic value.
 * @param val2 Second diagnostic value.
 * @param val3 Third diagnostic value.
 * @param val4 Fourth diagnostic value.
 * @param val5 Fifth diagnostic value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_diagnostic_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float val1,float val2,float val3,float val4,float val5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[20];
	_mav_put_float(buf, 0, val1);
	_mav_put_float(buf, 4, val2);
	_mav_put_float(buf, 8, val3);
	_mav_put_float(buf, 12, val4);
	_mav_put_float(buf, 16, val5);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 20);
#else
	mavlink_diagnostic_t packet;
	packet.val1 = val1;
	packet.val2 = val2;
	packet.val3 = val3;
	packet.val4 = val4;
	packet.val5 = val5;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 20);
#endif

	msg->msgid = MAVLINK_MSG_ID_DIAGNOSTIC;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 20, 150);
}

/**
 * @brief Encode a diagnostic struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param diagnostic C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_diagnostic_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_diagnostic_t* diagnostic)
{
	return mavlink_msg_diagnostic_pack(system_id, component_id, msg, diagnostic->val1, diagnostic->val2, diagnostic->val3, diagnostic->val4, diagnostic->val5);
}

/**
 * @brief Send a diagnostic message
 * @param chan MAVLink channel to send the message
 *
 * @param val1 First diagnostic value.
 * @param val2 Second diagnostic value.
 * @param val3 Third diagnostic value.
 * @param val4 Fourth diagnostic value.
 * @param val5 Fifth diagnostic value.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_diagnostic_send(mavlink_channel_t chan, float val1, float val2, float val3, float val4, float val5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[20];
	_mav_put_float(buf, 0, val1);
	_mav_put_float(buf, 4, val2);
	_mav_put_float(buf, 8, val3);
	_mav_put_float(buf, 12, val4);
	_mav_put_float(buf, 16, val5);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIAGNOSTIC, buf, 20, 150);
#else
	mavlink_diagnostic_t packet;
	packet.val1 = val1;
	packet.val2 = val2;
	packet.val3 = val3;
	packet.val4 = val4;
	packet.val5 = val5;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DIAGNOSTIC, (const char *)&packet, 20, 150);
#endif
}

#endif

// MESSAGE DIAGNOSTIC UNPACKING


/**
 * @brief Get field val1 from diagnostic message
 *
 * @return First diagnostic value.
 */
static inline float mavlink_msg_diagnostic_get_val1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field val2 from diagnostic message
 *
 * @return Second diagnostic value.
 */
static inline float mavlink_msg_diagnostic_get_val2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field val3 from diagnostic message
 *
 * @return Third diagnostic value.
 */
static inline float mavlink_msg_diagnostic_get_val3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field val4 from diagnostic message
 *
 * @return Fourth diagnostic value.
 */
static inline float mavlink_msg_diagnostic_get_val4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field val5 from diagnostic message
 *
 * @return Fifth diagnostic value.
 */
static inline float mavlink_msg_diagnostic_get_val5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a diagnostic message into a struct
 *
 * @param msg The message to decode
 * @param diagnostic C-struct to decode the message contents into
 */
static inline void mavlink_msg_diagnostic_decode(const mavlink_message_t* msg, mavlink_diagnostic_t* diagnostic)
{
#if MAVLINK_NEED_BYTE_SWAP
	diagnostic->val1 = mavlink_msg_diagnostic_get_val1(msg);
	diagnostic->val2 = mavlink_msg_diagnostic_get_val2(msg);
	diagnostic->val3 = mavlink_msg_diagnostic_get_val3(msg);
	diagnostic->val4 = mavlink_msg_diagnostic_get_val4(msg);
	diagnostic->val5 = mavlink_msg_diagnostic_get_val5(msg);
#else
	memcpy(diagnostic, _MAV_PAYLOAD(msg), 20);
#endif
}
