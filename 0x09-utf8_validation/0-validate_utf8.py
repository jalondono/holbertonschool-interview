#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """ determines if a given data set
        represents a valid UTF-8 encoding
    """
    d = data
    labels = [False for n in d]
    i = 0
    while i < len(d):
        if d[i] < 128:
            labels[i] = True
            i += 1
        elif d[i] & 248 == 240:
            if (i+3 <= len(d)-1):
                labels[i] = True
                i += 1
                for n in range(3):
                    if d[i+n] & 192 == 128:
                        labels[i+n] = True
                    else:
                        break
                i += 3
            else:
                break
        elif d[i] & 240 == 224:
            if (i+2 <= len(d)-1):
                labels[i] = True
                i += 1
                for n in range(2):
                    if d[i+n] & 192 == 128:
                        labels[i+n] = True
                    else:
                        break
                i += 2
            else:
                break
        elif d[i] & 224 == 192:
            if (i+1 <= len(d)-1):
                labels[i] = True
                i += 1
                if d[i] & 192 == 128:
                    labels[i] = True
                i += 1
            else:
                break
        else:
            break
    return all(labels)
