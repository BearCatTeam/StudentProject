
(cl:in-package :asdf)

(defsystem "face_detector-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "TurnServo" :depends-on ("_package_TurnServo"))
    (:file "_package_TurnServo" :depends-on ("_package"))
  ))