// MESSAGE VSCL_AUTOLAND PACKING

#define MAVLINK_MSG_ID_VSCL_AUTOLAND 203

typedef struct __mavlink_vscl_autoland_t
{
 int32_t time; ///< CPU time in milliseconds.
 int16_t psi; ///< Reference heading (mrad).
 int16_t theta; ///< Reference pitch (mrad).
 int16_t phi; ///< Reference bank (mrad).
 int16_t elev; ///< Elevator setting (cd).
 int16_t thto; ///< Throttle setting (pct?).
 int16_t aile; ///< Aileron setting (cd).
} mavlink_vscl_autoland_t;

#define MAVLINK_MSG_ID_VSCL_AUTOLAND_LEN 16
#define MAVLINK_MSG_ID_203_LEN 16



#define MAVLINK_MESSAGE_INFO_VSCL_AUTOLAND { \
	"VSCL_AUTOLAND", \
	7, \
	{  { "time", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_vscl_autoland_t, time) }, \
         { "psi", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vscl_autoland_t, psi) }, \
         { "theta", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vscl_autoland_t, theta) }, \
         { "phi", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vscl_autoland_t, phi) }, \
         { "elev", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_vscl_autoland_t, elev) }, \
         { "thto", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_vscl_autoland_t, thto) }, \
         { "aile", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_vscl_autoland_t, aile) }, \
         } \
}


/**
 * @brief Pack a vscl_autoland message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time CPU time in milliseconds.
 * @param psi Reference heading (mrad).
 * @param theta Reference pitch (mrad).
 * @param phi Reference bank (mrad).
 * @param elev Elevator setting (cd).
 * @param thto Throttle setting (pct?).
 * @param aile Aileron setting (cd).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_autoland_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t time, int16_t psi, int16_t theta, int16_t phi, int16_t elev, int16_t thto, int16_t aile)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[16];
	_mav_put_int32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, psi);
	_mav_put_int16_t(buf, 6, theta);
	_mav_put_int16_t(buf, 8, phi);
	_mav_put_int16_t(buf, 10, elev);
	_mav_put_int16_t(buf, 12, thto);
	_mav_put_int16_t(buf, 14, aile);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 16);
#else
	mavlink_vscl_autoland_t packet;
	packet.time = time;
	packet.psi = psi;
	packet.theta = theta;
	packet.phi = phi;
	packet.elev = elev;
	packet.thto = thto;
	packet.aile = aile;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 16);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_AUTOLAND;
	return mavlink_finalize_message(msg, system_id, component_id, 16, 189);
}

/**
 * @brief Pack a vscl_autoland message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param time CPU time in milliseconds.
 * @param psi Reference heading (mrad).
 * @param theta Reference pitch (mrad).
 * @param phi Reference bank (mrad).
 * @param elev Elevator setting (cd).
 * @param thto Throttle setting (pct?).
 * @param aile Aileron setting (cd).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vscl_autoland_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t time,int16_t psi,int16_t theta,int16_t phi,int16_t elev,int16_t thto,int16_t aile)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[16];
	_mav_put_int32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, psi);
	_mav_put_int16_t(buf, 6, theta);
	_mav_put_int16_t(buf, 8, phi);
	_mav_put_int16_t(buf, 10, elev);
	_mav_put_int16_t(buf, 12, thto);
	_mav_put_int16_t(buf, 14, aile);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 16);
#else
	mavlink_vscl_autoland_t packet;
	packet.time = time;
	packet.psi = psi;
	packet.theta = theta;
	packet.phi = phi;
	packet.elev = elev;
	packet.thto = thto;
	packet.aile = aile;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 16);
#endif

	msg->msgid = MAVLINK_MSG_ID_VSCL_AUTOLAND;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 16, 189);
}

/**
 * @brief Encode a vscl_autoland struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vscl_autoland C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vscl_autoland_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vscl_autoland_t* vscl_autoland)
{
	return mavlink_msg_vscl_autoland_pack(system_id, component_id, msg, vscl_autoland->time, vscl_autoland->psi, vscl_autoland->theta, vscl_autoland->phi, vscl_autoland->elev, vscl_autoland->thto, vscl_autoland->aile);
}

/**
 * @brief Send a vscl_autoland message
 * @param chan MAVLink channel to send the message
 *
 * @param time CPU time in milliseconds.
 * @param psi Reference heading (mrad).
 * @param theta Reference pitch (mrad).
 * @param phi Reference bank (mrad).
 * @param elev Elevator setting (cd).
 * @param thto Throttle setting (pct?).
 * @param aile Aileron setting (cd).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vscl_autoland_send(mavlink_channel_t chan, int32_t time, int16_t psi, int16_t theta, int16_t phi, int16_t elev, int16_t thto, int16_t aile)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[16];
	_mav_put_int32_t(buf, 0, time);
	_mav_put_int16_t(buf, 4, psi);
	_mav_put_int16_t(buf, 6, theta);
	_mav_put_int16_t(buf, 8, phi);
	_mav_put_int16_t(buf, 10, elev);
	_mav_put_int16_t(buf, 12, thto);
	_mav_put_int16_t(buf, 14, aile);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_AUTOLAND, buf, 16, 189);
#else
	mavlink_vscl_autoland_t packet;
	packet.time = time;
	packet.psi = psi;
	packet.theta = theta;
	packet.phi = phi;
	packet.elev = elev;
	packet.thto = thto;
	packet.aile = aile;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VSCL_AUTOLAND, (const char *)&packet, 16, 189);
#endif
}

#endif

// MESSAGE VSCL_AUTOLAND UNPACKING


/**
 * @brief Get field time from vscl_autoland message
 *
 * @return CPU time in milliseconds.
 */
static inline int32_t mavlink_msg_vscl_autoland_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field psi from vscl_autoland message
 *
 * @return Reference heading (mrad).
 */
static inline int16_t mavlink_msg_vscl_autoland_get_psi(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field theta from vscl_autoland message
 *
 * @return Reference pitch (mrad).
 */
static inline int16_t mavlink_msg_vscl_autoland_get_theta(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field phi from vscl_autoland message
 *
 * @return Reference bank (mrad).
 */
static inline int16_t mavlink_msg_vscl_autoland_get_phi(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field elev from vscl_autoland message
 *
 * @return Elevator setting (cd).
 */
static inline int16_t mavlink_msg_vscl_autoland_get_elev(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field thto from vscl_autoland message
 *
 * @return Throttle setting (pct?).
 */
static inline int16_t mavlink_msg_vscl_autoland_get_thto(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field aile from vscl_autoland message
 *
 * @return Aileron setting (cd).
 */
static inline int16_t mavlink_msg_vscl_autoland_get_aile(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a vscl_autoland message into a struct
 *
 * @param msg The message to decode
 * @param vscl_autoland C-struct to decode the message contents into
 */
static inline void mavlink_msg_vscl_autoland_decode(const mavlink_message_t* msg, mavlink_vscl_autoland_t* vscl_autoland)
{
#if MAVLINK_NEED_BYTE_SWAP
	vscl_autoland->time = mavlink_msg_vscl_autoland_get_time(msg);
	vscl_autoland->psi = mavlink_msg_vscl_autoland_get_psi(msg);
	vscl_autoland->theta = mavlink_msg_vscl_autoland_get_theta(msg);
	vscl_autoland->phi = mavlink_msg_vscl_autoland_get_phi(msg);
	vscl_autoland->elev = mavlink_msg_vscl_autoland_get_elev(msg);
	vscl_autoland->thto = mavlink_msg_vscl_autoland_get_thto(msg);
	vscl_autoland->aile = mavlink_msg_vscl_autoland_get_aile(msg);
#else
	memcpy(vscl_autoland, _MAV_PAYLOAD(msg), 16);
#endif
}
