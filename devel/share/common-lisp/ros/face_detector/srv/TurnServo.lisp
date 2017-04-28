; Auto-generated. Do not edit!


(cl:in-package face_detector-srv)


;//! \htmlinclude TurnServo-request.msg.html

(cl:defclass <TurnServo-request> (roslisp-msg-protocol:ros-message)
  ((order
    :reader order
    :initarg :order
    :type cl:string
    :initform ""))
)

(cl:defclass TurnServo-request (<TurnServo-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TurnServo-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TurnServo-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_detector-srv:<TurnServo-request> is deprecated: use face_detector-srv:TurnServo-request instead.")))

(cl:ensure-generic-function 'order-val :lambda-list '(m))
(cl:defmethod order-val ((m <TurnServo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_detector-srv:order-val is deprecated.  Use face_detector-srv:order instead.")
  (order m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TurnServo-request>) ostream)
  "Serializes a message object of type '<TurnServo-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'order))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'order))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TurnServo-request>) istream)
  "Deserializes a message object of type '<TurnServo-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'order) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'order) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TurnServo-request>)))
  "Returns string type for a service object of type '<TurnServo-request>"
  "face_detector/TurnServoRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TurnServo-request)))
  "Returns string type for a service object of type 'TurnServo-request"
  "face_detector/TurnServoRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TurnServo-request>)))
  "Returns md5sum for a message object of type '<TurnServo-request>"
  "9e8900160e632bc440efbe0cc2cd41d3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TurnServo-request)))
  "Returns md5sum for a message object of type 'TurnServo-request"
  "9e8900160e632bc440efbe0cc2cd41d3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TurnServo-request>)))
  "Returns full string definition for message of type '<TurnServo-request>"
  (cl:format cl:nil "string order~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TurnServo-request)))
  "Returns full string definition for message of type 'TurnServo-request"
  (cl:format cl:nil "string order~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TurnServo-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'order))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TurnServo-request>))
  "Converts a ROS message object to a list"
  (cl:list 'TurnServo-request
    (cl:cons ':order (order msg))
))
;//! \htmlinclude TurnServo-response.msg.html

(cl:defclass <TurnServo-response> (roslisp-msg-protocol:ros-message)
  ((errorcode
    :reader errorcode
    :initarg :errorcode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass TurnServo-response (<TurnServo-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TurnServo-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TurnServo-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_detector-srv:<TurnServo-response> is deprecated: use face_detector-srv:TurnServo-response instead.")))

(cl:ensure-generic-function 'errorcode-val :lambda-list '(m))
(cl:defmethod errorcode-val ((m <TurnServo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_detector-srv:errorcode-val is deprecated.  Use face_detector-srv:errorcode instead.")
  (errorcode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TurnServo-response>) ostream)
  "Serializes a message object of type '<TurnServo-response>"
  (cl:let* ((signed (cl:slot-value msg 'errorcode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TurnServo-response>) istream)
  "Deserializes a message object of type '<TurnServo-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'errorcode) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TurnServo-response>)))
  "Returns string type for a service object of type '<TurnServo-response>"
  "face_detector/TurnServoResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TurnServo-response)))
  "Returns string type for a service object of type 'TurnServo-response"
  "face_detector/TurnServoResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TurnServo-response>)))
  "Returns md5sum for a message object of type '<TurnServo-response>"
  "9e8900160e632bc440efbe0cc2cd41d3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TurnServo-response)))
  "Returns md5sum for a message object of type 'TurnServo-response"
  "9e8900160e632bc440efbe0cc2cd41d3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TurnServo-response>)))
  "Returns full string definition for message of type '<TurnServo-response>"
  (cl:format cl:nil "int8 errorcode~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TurnServo-response)))
  "Returns full string definition for message of type 'TurnServo-response"
  (cl:format cl:nil "int8 errorcode~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TurnServo-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TurnServo-response>))
  "Converts a ROS message object to a list"
  (cl:list 'TurnServo-response
    (cl:cons ':errorcode (errorcode msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'TurnServo)))
  'TurnServo-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'TurnServo)))
  'TurnServo-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TurnServo)))
  "Returns string type for a service object of type '<TurnServo>"
  "face_detector/TurnServo")