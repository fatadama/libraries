// MESSAGE VSCL_CONTROLS PACKING

#define MAVLINK_MSG_ID_VSCL_CONTROLS 202

typedef struct __mavlink_vscl_controls_t
{
 int16_t elev; ///< Elevator setting.
 int16_t thro; ///< Throttle setting.
 int16_t aile; ///< Aileron setting.
 int16_t rudd; ///< Rudder setting.
} mavlink_vscl_controls_t;

#define MAVLINK_MSG_ID_VSCL_CONTROLS_LEN 8
#define MAVLINK_MSG_ID_202_LEN 8



#define MAVLINK_MESSAGE_INFO_VSCL_CONTROLS { \
	"VSCL_CONTROLS", \
	4, \
	{  { "elev", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_vscl_controls_t, elev) }, \
         { "thro", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_vscl_controls_t, thro) }, \
         { "aile", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vscl_controls_t, aile) }, \
         { "rudd", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vscl_controls_t, rudd) }, \
         } \
}


/**
 * @brief Pack a vscl_controls message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param elev Elevator setting.
 * @param thro Throttle setting.
 * @param aile Aileron setting.
 * @param rudd Rudder setting.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_controls_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t elev, int16_t thro, int16_t aile, int16_t rudd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_int16_t(buf, 0, elev);
	_mav_put_int16_t(buf, 2, thro);
	_mav_put_int16_t(buf, 4, aile);
	_mav_put_int16_t(buf, 6, rudd);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_vscl_controls_t packet;
	packet.elev = elev;
	packet.thro = thro;
	packet.aile = aile;
	packet.rudd = rudd;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_CONTROLS;
	return mavlink_finalize_message(msg, system_id, component_id, 8, 91);
}

/**
 * @brief Pack a vscl_controls message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param elev Elevator setting.
 * @param thro Throttle setting.
 * @param aile Aileron setting.
 * @param rudd Rudder setting.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_controls_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t elev,int16_t thro,int16_t aile,int16_t rudd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_int16_t(buf, 0, elev);
	_mav_put_int16_t(buf, 2, thro);
	_mav_put_int16_t(buf, 4, aile);
	_mav_put_int16_t(buf, 6, rudd);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_vscl_controls_t packet;
	packet.elev = elev;
	packet.thro = thro;
	packet.aile = aile;
	packet.rudd = rudd;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_CONTROLS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 8, 91);
}

/**
 * @brief Encode a vscl_controls struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vscl_controls C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vscl_controls_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vscl_controls_t* vscl_controls)
{
	return mavlink_msg_vscl_controls_pack(system_id, component_id, msg, vscl_controls->elev, vscl_controls->thro, vscl_controls->aile, vscl_controls->rudd);
}

/**
 * @brief Send a vscl_controls message
 * @param chan MAVLink channel to send the message
 *
 * @param elev Elevator setting.
 * @param thro Throttle setting.
 * @param aile Aileron setting.
 * @param rudd Rudder setting.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vscl_controls_send(mavlink_channel_t chan, int16_t elev, int16_t thro, int16_t aile, int16_t rudd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_int16_t(buf, 0, elev);
	_mav_put_int16_t(buf, 2, thro);
	_mav_put_int16_t(buf, 4, aile);
	_mav_put_int16_t(buf, 6, rudd);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_CONTROLS, buf, 8, 91);
#else
	mavlink_vscl_controls_t packet;
	packet.elev = elev;
	packet.thro = thro;
	packet.aile = aile;
	packet.rudd = rudd;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_CONTROLS, (const char *)&packet, 8, 91);
#endif
}

#endif

// MESSAGE VSCL_CONTROLS UNPACKING


/**
 * @brief Get field elev from vscl_controls message
 *
 * @return Elevator setting.
 */
static inline int16_t mavlink_msg_vscl_controls_get_elev(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field thro from vscl_controls message
 *
 * @return Throttle setting.
 */
static inline int16_t mavlink_msg_vscl_controls_get_thro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field aile from vscl_controls message
 *
 * @return Aileron setting.
 */
static inline int16_t mavlink_msg_vscl_controls_get_aile(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field rudd from vscl_controls message
 *
 * @return Rudder setting.
 */
static inline int16_t mavlink_msg_vscl_controls_get_rudd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Decode a vscl_controls message into a struct
 *
 * @param msg The message to decode
 * @param vscl_controls C-struct to decode the message contents into
 */
static inline void mavlink_msg_vscl_controls_decode(const mavlink_message_t* msg, mavlink_vscl_controls_t* vscl_controls)
{
#if MAVLINK_NEED_BYTE_SWAP
	vscl_controls->elev = mavlink_msg_vscl_controls_get_elev(msg);
	vscl_controls->thro = mavlink_msg_vscl_controls_get_thro(msg);
	vscl_controls->aile = mavlink_msg_vscl_controls_get_aile(msg);
	vscl_controls->rudd = mavlink_msg_vscl_controls_get_rudd(msg);
#else
	memcpy(vscl_controls, _MAV_PAYLOAD(msg), 8);
#endif
}
