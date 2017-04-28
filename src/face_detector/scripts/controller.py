#!/usr/bin/env python

import rospy
import numpy as np
import math
from std_msgs.msg import String

#################### INITIAL VALUE ###################
pub = rospy.Publisher('head_angle', String, queue_size=1)
rospy.init_node('pc_controller_node', anonymous=True)
servo_angles = str(0) + " " + str(0)

servo_arm_length = 23 ## in mm
servo_link_length = 170 ## in mm

AB_length = 172 ## in mm
DC_length = 172 ## in mm

roll_angle = 0
pitch_angle = 0

alpha = 90
beta = 90

Rx_mat = np.array([[1,0,0],[0,math.cos(math.radians(0)),-math.sin(math.radians(0))],[0,math.sin(math.radians(0)),math.cos(math.radians(0))]])
Ry_mat = np.array([[math.cos(math.radians(0)),0,math.sin(math.radians(0))],[0,1,0],[-math.sin(math.radians(0)),0,math.cos(math.radians(0))]])
Rz_mat = np.array([[math.cos(math.radians(0)), -math.sin(math.radians(0)), 0],[math.sin(math.radians(0)),math.cos(math.radians(0)),0],[0,0,1]])
Rotation_OF = np.dot(Rz_mat,Ry_mat)
Rotation_OF = np.dot(Rotation_OF,Rx_mat)

OA_vectO = np.array([[48.93618293], [69.5], [0.0]])
OD_vectO = np.array([[48.93618293], [-69.5], [0.0]])
OF_vectO = np.array([[0.0], [0.0], [141.0]]) # frame O vectors
EC_vectF = np.array([[54.61670609], [-62.4981233], [30.0]])
EB_vectF = np.array([[54.6145585], [62.5], [30.0]])
FE_vectF = np.array([[0.0], [0.0], [30.0]]) # frame E vectors
FC_vectF = FC_vectO = np.zeros((3,1))
FB_vectF = FB_vectO = np.zeros((3,1))
AB_vectO = DC_vectO = np.zeros((3,1))


#### FUNCTION TO PUBLISH ROS TOPIC DATA TO ARDUINO ###
def publishing_function(alpha, beta):
    global servo_angles
    servo_angles = str(alpha) + " " + str(beta)
    global pub
    pub.publish(servo_angles)

######################################################
def calculate_angles():
    global FC_vectF
    FC_vectF = FE_vectF + EC_vectF
    print("FC_vectF = ",FC_vectF)

    global FB_vectF
    FB_vectF = FE_vectF + EB_vectF
    print("FB_vectF = ",FB_vectF)

    global Rx_mat
    Rx_mat=np.array([[1,0,0],[0,math.cos(math.radians(roll_angle)),-math.sin(math.radians(roll_angle))],[0,math.sin(math.radians(roll_angle)),math.cos(math.radians(roll_angle))]])
    print("Rx_mat = ",Rx_mat)

    global Ry_mat
    Ry_mat=np.array([[math.cos(math.radians(pitch_angle)),0,math.sin(math.radians(pitch_angle))],[0,1,0],[-math.sin(math.radians(pitch_angle)),0,math.cos(math.radians(pitch_angle))]])
    print("Ry_mat = ",Ry_mat)

    global Rz_mat
    print("Rz_mat = ",Rz_mat)
    global Rotation_mat
    Rotation_OF = np.dot(Rz_mat,Ry_mat)
    Rotation_OF = np.dot(Rotation_OF,Rx_mat)
    print("Rotation_OF = ",Rotation_OF)

    global FC_vectO
    FC_vectO = np.dot(Rotation_OF,FC_vectF)
    print("FC_vectO = ",FC_vectO)

    global FB_vectO
    FB_vectO = np.dot(Rotation_OF,FB_vectF)
    print("FB_vectO = ",FB_vectO)

    global AB_vectO
    AB_vectO = OF_vectO+FB_vectO-OA_vectO
    print("AB_vectO = ",AB_vectO)

    global DC_vectO
    DC_vectO = OF_vectO+FC_vectO-OD_vectO
    print("DC_vectO = ",DC_vectO)

    global DC_length
    DC_length = np.dot(np.transpose(DC_vectO),DC_vectO)
    print("DC_length = ",math.sqrt(DC_length))

    global AB_length
    AB_length = np.dot(np.transpose(AB_vectO),AB_vectO)
    print("AB_length = ",math.sqrt(AB_length))

    cos_alpha = float(AB_length+math.pow(servo_arm_length,2)-math.pow(servo_link_length,2))/(2*math.sqrt(AB_length)*servo_arm_length)
    print("cos_alpha = ",cos_alpha)
    alpha_rad = math.acos(cos_alpha)
    print("alpha_rad = ",alpha_rad)
    global alpha
    alpha=int((alpha_rad*180)/(math.pi))
    print("alpha = ",alpha)

    cos_beta = float(DC_length+math.pow(servo_arm_length,2)-math.pow(servo_link_length,2))/(2*math.sqrt(DC_length)*servo_arm_length)
    print("cos_beta = ",cos_beta)
    beta_rad = math.acos(cos_beta)
    print("beta_rad = ",beta_rad)
    global beta
    beta = int((beta_rad*180)/(math.pi))
    print("beta = ",beta)

    try:
        publishing_function(alpha,beta)
    except rospy.ROSInterruptException:
        pass

######################################################
if __name__ == '__main__':
        publishing_function(alpha,beta)
        roll_angle=input("Input_Roll_Angle:")
        pitch_angle=input("Input_Pitch_Angle:")
        calculate_angles()
