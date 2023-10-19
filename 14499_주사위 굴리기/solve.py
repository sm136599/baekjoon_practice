import sys

readl = sys.stdin.readline
N, M, x, y, K = map(int, readl().split())
field = [list(map(int, readl().split())) for _ in range(N)]
statement = list(map(int, readl().split()))

SKY = 0; GROUND = -1; EAST = 1; WEST = 2; NORTH = 3; SOUTH = 4
class Dice():
    def __init__(self, x, y, N, M):
        # 각 숫자는 보고 있는 방향
        self.dice = {SKY: 0, SOUTH: 0, EAST: 0, WEST: 0, NORTH: 0, GROUND: 0}
        self.current_x = x
        self.current_y = y
        self.N = N
        self.M = M
    
    def move(self, dir):
        if dir == EAST:
            if self.current_y + 1 < self.M:
                tmp = self.dice[EAST]
                self.dice[EAST] = self.dice[SKY]
                self.dice[SKY] = self.dice[WEST]
                self.dice[WEST] = self.dice[GROUND]
                self.dice[GROUND] = tmp
                self.current_y += 1
                return True
            return False
        elif dir == WEST:
            if self.current_y - 1 >= 0:
                tmp = self.dice[WEST]
                self.dice[WEST] = self.dice[SKY]
                self.dice[SKY] = self.dice[EAST]
                self.dice[EAST] = self.dice[GROUND]
                self.dice[GROUND] = tmp
                self.current_y -= 1
                return True
            return False
        elif dir == NORTH:
            if self.current_x - 1 >= 0:
                tmp = self.dice[NORTH]
                self.dice[NORTH] = self.dice[SKY]
                self.dice[SKY] = self.dice[SOUTH]
                self.dice[SOUTH] = self.dice[GROUND]
                self.dice[GROUND] = tmp
                self.current_x -= 1
                return True
            return False
        elif dir == SOUTH:
            if self.current_x + 1 < self.N:
                tmp = self.dice[SOUTH]
                self.dice[SOUTH] = self.dice[SKY]
                self.dice[SKY] = self.dice[NORTH]
                self.dice[NORTH] = self.dice[GROUND]
                self.dice[GROUND] = tmp
                self.current_x += 1
                return True
            return False
        
    def get_current_xy(self):
        return self.current_x, self.current_y

    def set_ground(self, val):
        self.dice[GROUND] = val
    
    def get_ground(self):
        return self.dice[GROUND]
    
    def get_sky(self):
        return self.dice[SKY]
    

    
dice = Dice(x, y, N, M)

for state in statement:
    if dice.move(state):
        x, y = dice.get_current_xy()
        if field[x][y] == 0:
            field[x][y] = dice.get_ground()
        else:
            dice.set_ground(field[x][y])
            field[x][y] = 0
        
        print(dice.get_sky())