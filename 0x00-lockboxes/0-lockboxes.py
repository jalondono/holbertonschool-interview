#!/usr/bin/python3
""" Lockboxes"""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you."""
    id_opened_boxes = [0]
    number_boxes = len(boxes)

    for id_open in id_opened_boxes:
        for current_id in boxes[id_open]:
            if current_id < number_boxes and current_id not in id_opened_boxes:
                id_opened_boxes.append(current_id)
    if len(id_opened_boxes) == number_boxes:
        return True
    return False



