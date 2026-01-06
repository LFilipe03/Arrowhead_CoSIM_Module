#!/usr/bin/env python3

import os
import random

def generate_random_vehicle_position():
    number_of_vehicles = random.randint(2, 5)
    valid_position = False
    x_pos_array = []
    y_pos_array = []

    for i in range(number_of_vehicles):


        if(i == 0):
            x = random.randint(-8, 100)
            y = random.randint(0, 1)

            if y == 0:
                y = 7.1
            else:
                y = 3.6

        else: 
            while valid_position == False:
                x = random.randint(-8, 65)
                y = random.randint(0, 1)

                if y == 0:
                    y = 7.1
                else:
                    y = 3.6

                #print("Debug: Pos " + str(x) + " is being checked")
                for j in range(len(x_pos_array)):
                    if x > (x_pos_array[j] - 10) and x < (x_pos_array[j] + 10) and y == y_pos_array[j]:
                        x = random.randint(-8, 65)
                        valid_position = False
                        break
                    else:
                        valid_position = True
                

        x_pos_array.append(x)
        y_pos_array.append(y)

        valid_position = False
        
    vehicle_position_array = [(x, y) for x, y in zip(x_pos_array, y_pos_array)]
    
    return vehicle_position_array

