// MESSAGE VSCL_BUMP PACKING

#define MAVLINK_MSG_ID_VSCL_BUMP 201

typedef struct __mavlink_vscl_bump_t
{
 int16_t bumpval; ///< The amount by which to change value.
 uint8_t bumpID; ///< The value to change. 0 = altitude, 1 = airspeed.
} mavlink_vscl_bump_t;

#define MAVLINK_MSG_ID_VSCL_BUMP_LEN 3
#define MAVLINK_MSG_ID_201_LEN 3



#define MAVLINK_MESSAGE_INFO_VSCL_BUMP { \
	"VSCL_BUMP", \
	2, \
	{  { "bumpval", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_vscl_bump_t, bumpval) }, \
         { "bumpID", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_vscl_bump_t, bumpID) }, \
         } \
}


/**
 * @brief Pack a vscl_bump message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param bumpval The amount by which to change value.
 * @param bumpID The value to change. 0 = altitude, 1 = airspeed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_bump_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t bumpval, uint8_t bumpID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_int16_t(buf, 0, bumpval);
	_mav_put_uint8_t(buf, 2, bumpID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 3);
#else
	mavlink_vscl_bump_t packet;
	packet.bumpval = bumpval;
	packet.bumpID = bumpID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_BUMP;
	return mavlink_finalize_message(msg, system_id, component_id, 3, 185);
}

/**
 * @brief Pack a vscl_bump message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param bumpval The amount by which to change value.
 * @param bumpID The value to change. 0 = altitude, 1 = airspeed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_bump_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t bumpval,uint8_t bumpID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_int16_t(buf, 0, bumpval);
	_mav_put_uint8_t(buf, 2, bumpID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 3);
#else
	mavlink_vscl_bump_t packet;
	packet.bumpval = bumpval;
	packet.bumpID = bumpID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 3);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_BUMP;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 3, 185);
}

/**
 * @brief Encode a vscl_bump struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vscl_bump C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vscl_bump_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vscl_bump_t* vscl_bump)
{
	return mavlink_msg_vscl_bump_pack(system_id, component_id, msg, vscl_bump->bumpval, vscl_bump->bumpID);
}

/**
 * @brief Send a vscl_bump message
 * @param chan MAVLink channel to send the message
 *
 * @param bumpval The amount by which to change value.
 * @param bumpID The value to change. 0 = altitude, 1 = airspeed.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vscl_bump_send(mavlink_channel_t chan, int16_t bumpval, uint8_t bumpID)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[3];
	_mav_put_int16_t(buf, 0, bumpval);
	_mav_put_uint8_t(buf, 2, bumpID);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_BUMP, buf, 3, 185);
#else
	mavlink_vscl_bump_t packet;
	packet.bumpval = bumpval;
	packet.bumpID = bumpID;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_BUMP, (const char *)&packet, 3, 185);
#endif
}

#endif

// MESSAGE VSCL_BUMP UNPACKING


/**
 * @brief Get field bumpval from vscl_bump message
 *
 * @return The amount by which to change value.
 */
static inline int16_t mavlink_msg_vscl_bump_get_bumpval(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field bumpID from vscl_bump message
 *
 * @return The value to change. 0 = altitude, 1 = airspeed.
 */
static inline uint8_t mavlink_msg_vscl_bump_get_bumpID(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a vscl_bump message into a struct
 *
 * @param msg The message to decode
 * @param vscl_bump C-struct to decode the message contents into
 */
static inline void mavlink_msg_vscl_bump_decode(const mavlink_message_t* msg, mavlink_vscl_bump_t* vscl_bump)
{
#if MAVLINK_NEED_BYTE_SWAP
	vscl_bump->bumpval = mavlink_msg_vscl_bump_get_bumpval(msg);
	vscl_bump->bumpID = mavlink_msg_vscl_bump_get_bumpID(msg);
#else
	memcpy(vscl_bump, _MAV_PAYLOAD(msg), 3);
#endif
}
