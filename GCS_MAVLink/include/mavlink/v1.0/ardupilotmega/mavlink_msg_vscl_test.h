// MESSAGE VSCL_TEST PACKING

#define MAVLINK_MSG_ID_VSCL_TEST 200

typedef struct __mavlink_vscl_test_t
{
 uint16_t dummy; ///< A dummy value, the MAV will echo it.
} mavlink_vscl_test_t;

#define MAVLINK_MSG_ID_VSCL_TEST_LEN 2
#define MAVLINK_MSG_ID_200_LEN 2



#define MAVLINK_MESSAGE_INFO_VSCL_TEST { \
	"VSCL_TEST", \
	1, \
	{  { "dummy", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_vscl_test_t, dummy) }, \
         } \
}


/**
 * @brief Pack a vscl_test message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dummy A dummy value, the MAV will echo it.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_test_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t dummy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint16_t(buf, 0, dummy);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_vscl_test_t packet;
	packet.dummy = dummy;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_TEST;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 144);
}

/**
 * @brief Pack a vscl_test message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param dummy A dummy value, the MAV will echo it.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_test_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t dummy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint16_t(buf, 0, dummy);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_vscl_test_t packet;
	packet.dummy = dummy;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_TEST;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 144);
}

/**
 * @brief Encode a vscl_test struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vscl_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vscl_test_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vscl_test_t* vscl_test)
{
	return mavlink_msg_vscl_test_pack(system_id, component_id, msg, vscl_test->dummy);
}

/**
 * @brief Send a vscl_test message
 * @param chan MAVLink channel to send the message
 *
 * @param dummy A dummy value, the MAV will echo it.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vscl_test_send(mavlink_channel_t chan, uint16_t dummy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint16_t(buf, 0, dummy);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_TEST, buf, 2, 144);
#else
	mavlink_vscl_test_t packet;
	packet.dummy = dummy;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_TEST, (const char *)&packet, 2, 144);
#endif
}

#endif

// MESSAGE VSCL_TEST UNPACKING


/**
 * @brief Get field dummy from vscl_test message
 *
 * @return A dummy value, the MAV will echo it.
 */
static inline uint16_t mavlink_msg_vscl_test_get_dummy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a vscl_test message into a struct
 *
 * @param msg The message to decode
 * @param vscl_test C-struct to decode the message contents into
 */
static inline void mavlink_msg_vscl_test_decode(const mavlink_message_t* msg, mavlink_vscl_test_t* vscl_test)
{
#if MAVLINK_NEED_BYTE_SWAP
	vscl_test->dummy = mavlink_msg_vscl_test_get_dummy(msg);
#else
	memcpy(vscl_test, _MAV_PAYLOAD(msg), 2);
#endif
}
