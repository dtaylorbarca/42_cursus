import math

def get_player_pos() -> tuple:
    while True:
        try:
            index = -1
            user_input = input("Enter new coordinates as floats in format 'x,y,z': ")
            pos = user_input.split(",")
            count = 0
            for _ in pos:
                count += 1
            if count != 3:
                raise IndexError
            index = 0
            x = float(pos[0])
            index = 1
            y = float(pos[1])
            index = 2
            z = float(pos[2])
            pos = (x, y, z)
        except IndexError:
            print("Invalid syntax")
            continue
        except ValueError as e:
            if index == 0:
                print(f"Error on parameter '{pos[0]}': {e}")
            elif index == 1:
                print(f"Error on parameter '{pos[1]}': {e}")
            elif index == 2:
                print(f"Error on parameter '{pos[2]}': {e}")
            continue
        else:
            return pos


def position_tracker() -> None:
    print("=== Game Coordinate System ===")
    print("\nGet a first set of coordinates")
    pos_1 = get_player_pos()
    print(f"Got a first tuple: {pos_1}")
    print(f"It includes: X={pos_1[0]}, Y={pos_1[1]}, Z={pos_1[2]}")
    distance_origin = round(math.sqrt(pos_1[0] ** 2 + pos_1[1] ** 2 + pos_1[2] ** 2), 4)
    print(f"Distance to centre: {distance_origin}")
    print("\nGet a second set of coordinates")
    pos_2 = get_player_pos()
    distance_x = pos_1[0] - pos_2[0]
    distance_y = pos_1[1] - pos_2[1]
    distance_z = pos_1[2] - pos_2[2]
    distance = round(math.sqrt(distance_x ** 2 + distance_y ** 2 + distance_z ** 2), 4)
    print(f"Distance between the 2 sets of coordinates: {distance}")


if __name__ == "__main__":
    position_tracker()
