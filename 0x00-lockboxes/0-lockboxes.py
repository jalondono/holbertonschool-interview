#!/usr/bin/python3
""" Lockboxes"""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you."""
    opened_boxes = {0: []}
    number_boxes = len(boxes)
    box_idx = 0
    finish_open = 0
    while finish_open == 0:
        flag_go_back = True
        if len(boxes[box_idx]) > 0:
            for key in boxes[box_idx]:
                if box_idx not in opened_boxes:
                    """Sino esta creado el campo, 
                    lo crea con una lista vaci"""
                    opened_boxes[box_idx] = []
                if key in opened_boxes[box_idx]:
                    continue
                """Recorrer los indices de las sublistas"""
                if key > number_boxes:
                    """si una key esta fuera de rango"""
                    return False
                if len(boxes[key]) == 0:
                    """si una caja esta nula, marquela como abierta"""
                    opened_boxes[key] = []
                    opened_boxes[box_idx].append(key)
                    flag_go_back = False
                else:
                    opened_boxes[box_idx].append(key)
                    box_idx = key
                    flag_go_back = False
                    break
        if flag_go_back:
            re_check = False
            for key, value in opened_boxes.items():
                if len(boxes[key]) != len(value):
                    box_idx = key
                    break
                else:
                    for element in value:
                        if len(boxes[element]) != len(opened_boxes[element]):
                            box_idx = element
                            re_check = True
                            break
                        else:
                            continue
                    if re_check:
                        break
                return False
        if len(opened_boxes) >= number_boxes:
            return True
