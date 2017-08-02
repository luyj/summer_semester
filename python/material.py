import pygame
from random import *
import os 
from pygame.locals import *

#建立子弹类
class Bullet(pygame.sprite.Sprite):
	def __init__(self,position,picture):
		pygame.sprite.Sprite.__init__(self)
		self.image=pygame.image.load(picture).convert_alpha()
		self.rect=self.image.get_rect()
		self.rect.left,self.rect.top = position
		self.speed=10
		self.active=False
		self.mask=pygame.mask.from_surface(self.image)
	def move(self,gunshot):
		self.rect.left+=self.speed
		if self.rect.left>gunshot+600:
			self.active=False
	def reset(self,position):
		self.rect.left,self.rect.top = position
		self.active=True

class BulletBlue(Bullet):
	def __init__(self,position):
		Bullet.__init__(self,position,"blue1.png")

class BulletGreen(Bullet):
	def __init__(self,position):
		Bullet.__init__(self,position,"ludou.png")

class BulletPurple(Bullet):
	def __init__(self,position):
		Bullet.__init__(self,position,"purple.png")

#建立植物类
class Grass(pygame.sprite.Sprite):
	_rate = 100
	bullet_index = 0
	bullet_num = 4

	def __init__(self,_number,num,top,left):
		self.i = 0
		self.order = 0
		self.energy = 0
		self.bullet = []
		self.flag = 0
		self.flag1 = 0
		self.active = True
		self.has = False

		pygame.sprite.Sprite.__init__(self)
		#加载植物一号
		if num==1:
			self.images.extend([\
				pygame.image.load("g1/g1.png").convert_alpha(),\
				pygame.image.load("g1/g2.png").convert_alpha(),\
				pygame.image.load("g1/g3.png").convert_alpha(),\
				pygame.image.load("g1/g4.png").convert_alpha(),\
				pygame.image.load("g1/g5.png").convert_alpha(),\
				pygame.image.load("g1/g6.png").convert_alpha(),\
				pygame.image.load("g1/g7.png").convert_alpha(),\
				pygame.image.load("g1/g8.png").convert_alpha(),\
				pygame.image.load("g1/g9.png").convert_alpha(),\
				pygame.image.load("g1/g10.png").convert_alpha(),\
				pygame.image.load("g1/g11.png").convert_alpha(),\
				pygame.image.load("g1/g12.png").convert_alpha(),\
				])
			self.image = self.images[self.order]
			self.rect = self.image.get_rect()
			for i in range(Grass.bullet_num):
				self.bullet.append(Bullet(self.rect.midtop,"ludou.png"))

		#加载植物二号
		elif num==2:
			self.images.extend([\
				pygame.image.load("g2/g1.png").convert_alpha(),\
				pygame.image.load("g2/g2.png").convert_alpha(),\
				pygame.image.load("g2/g3.png").convert_alpha(),\
				pygame.image.load("g2/g4.png").convert_alpha(),\
				pygame.image.load("g2/g5.png").convert_alpha(),\
				pygame.image.load("g2/g6.png").convert_alpha(),\
				pygame.image.load("g2/g7.png").convert_alpha(),\
				pygame.image.load("g2/g8.png").convert_alpha(),\
				pygame.image.load("g2/g9.png").convert_alpha(),\
				pygame.image.load("g2/g10.png").convert_alpha(),\
				pygame.image.load("g2/g11.png").convert_alpha(),\
				pygame.image.load("g2/g12.png").convert_alpha(),\
				pygame.image.load("g2/g13.png").convert_alpha(),\
				pygame.image.load("g2/g14.png").convert_alpha(),\
				pygame.image.load("g2/g15.png").convert_alpha(),\
				])
			self.image = self.images[self.order]
			self.rect = self.image.get_rect()
			for i in range(Grass.bullet_num):
				self.bullet.append(Bullet(self.rect.midtop,"blue1.png"))
		#加载植物三号
		elif num==3:

			self.images.extend([\
				pygame.image.load("g3/g1.png").convert_alpha(),\
				pygame.image.load("g3/g2.png").convert_alpha(),\
				pygame.image.load("g3/g3.png").convert_alpha(),\
				pygame.image.load("g3/g4.png").convert_alpha(),\
				pygame.image.load("g3/g5.png").convert_alpha(),\
				pygame.image.load("g3/g6.png").convert_alpha(),\
				pygame.image.load("g3/g7.png").convert_alpha(),\
				pygame.image.load("g3/g8.png").convert_alpha(),\
				pygame.image.load("g3/g9.png").convert_alpha(),\
				pygame.image.load("g3/g10.png").convert_alpha(),\
				pygame.image.load("g3/g11.png").convert_alpha(),\
				pygame.image.load("g3/g12.png").convert_alpha(),\
				])
			self.image = self.images[self.order]
			self.rect = self.image.get_rect()
			for i in range(Grass.bullet_num):
				self.bullet.append(Bullet(self.rect.midtop,"purple.png"))
		#加载植物四号
		elif num==4:
			self.images.extend([\
				pygame.image.load("b/b1.png").convert_alpha(),\
				pygame.image.load("b/b2.png").convert_alpha(),\
				pygame.image.load("b/b3.png").convert_alpha(),\
				pygame.image.load("b/b4.png").convert_alpha(),\
				pygame.image.load("b/b5.png").convert_alpha(),\
				pygame.image.load("b/b6.png").convert_alpha(),\
				pygame.image.load("b/b7.png").convert_alpha(),\
				pygame.image.load("b/b8.png").convert_alpha(),\
				])
			self.image = self.images[self.order]
			self.rect = self.image.get_rect()
		self.passed_time=0
				
		self.rect.top = top
		self.rect.left = left
		self.passed_time = 0
		self.mask=pygame.mask.from_surface(self.image)
	def move (self,x,y):
		self.rect.top = y-30
		self.rect.left = x-30
	def update(self,passed_time):
		self.passed_time += passed_time
		self.order = (self.passed_time / self._rate) % self.number
		if self.order == 0 and self.passed_time >self._rate:
			self.passed_time = 0
		self.image = self.images[int(self.order)]
	def bullet_move(self):
		if self.energy == self._energy:
			self.bullet[self.bullet_index].reset(self.rect.midtop)
		self.bullet_index = (self.bullet_index + 1) % self.bullet_num
#植物一号
class GreenGrass(Grass):
	_energy = 1
	_life=200
	images=[]
	number=12
	def __init__(self):
		Grass.__init__(self,12,1,10,220)
		self.life=GreenGrass._life
		self.sign=1
#植物二号
class BlueGrass(Grass):
	_energy = 1
	_life=120
	images=[]
	number=15
	def __init__(self):
		Grass.__init__(self,15,2,25,120)
		self.life=BlueGrass._life
		self.sign=2

class Fungus(Grass):
	_energy = 2
	_life=100
	number=12
	images=[]
	def __init__(self):
		self.sign=3
		Grass.__init__(self,12,3,20,10)
		self.life=Fungus._life
		

class Bomb(Grass):
	_energy = 5
	_life = 1
	number=8
	images=[]
	def __init__(self):
		self.sign=4
		Grass.__init__(self,8,4,10,320)
		self.life=Bomb._life
		 

#建立僵尸类
class Zombie(pygame.sprite.Sprite):

	_rate = 100
	energy=8
	def __init__(self,bg_size,_number,num):
		self.order = 0
		self.d1 = False
		self._number=_number
		self.passed_time=0
		self.active = True
		self.hit=False
		self.speed=1
		self.moveup=randint(-1,1)
		self.flag=0
		self.moving=True
		self.i=0

		pygame.sprite.Sprite.__init__(self)
		if num==1:
			self.images.extend([\
				pygame.image.load("z1/z1.png").convert_alpha(),\
				pygame.image.load("z1/z2.png").convert_alpha(),\
				pygame.image.load("z1/z3.png").convert_alpha(),\
				pygame.image.load("z1/z4.png").convert_alpha(),\
				pygame.image.load("z1/z5.png").convert_alpha(),\
				pygame.image.load("z1/z6.png").convert_alpha(),\
				pygame.image.load("z1/z7.png").convert_alpha(),\
				pygame.image.load("z1/z8.png").convert_alpha(),\
				pygame.image.load("z1/z9.png").convert_alpha(),\
				pygame.image.load("z1/z10.png").convert_alpha(),\
				pygame.image.load("z1/z11.png").convert_alpha(),\
				pygame.image.load("z1/z12.png").convert_alpha(),\
				])
		elif num==2:
			self.images.extend([\
				pygame.image.load("z2/z1.png").convert_alpha(),\
				pygame.image.load("z2/z2.png").convert_alpha(),\
				pygame.image.load("z2/z3.png").convert_alpha(),\
				pygame.image.load("z2/z4.png").convert_alpha(),\
				pygame.image.load("z2/z5.png").convert_alpha(),\
				pygame.image.load("z2/z6.png").convert_alpha(),\
				pygame.image.load("z2/z7.png").convert_alpha(),\
				pygame.image.load("z2/z8.png").convert_alpha(),\
				pygame.image.load("z2/z9.png").convert_alpha(),\
				pygame.image.load("z2/z10.png").convert_alpha(),\
				pygame.image.load("z2/z11.png").convert_alpha(),\
				pygame.image.load("z2/z12.png").convert_alpha(),\
				pygame.image.load("z2/z13.png").convert_alpha(),\
				pygame.image.load("z2/z14.png").convert_alpha(),\
				pygame.image.load("z2/z15.png").convert_alpha(),\
				pygame.image.load("z2/z16.png").convert_alpha(),\
				pygame.image.load("z2/z17.png").convert_alpha(),\
				pygame.image.load("z2/z18.png").convert_alpha(),\
				pygame.image.load("z2/z19.png").convert_alpha(),\
				pygame.image.load("z2/z20.png").convert_alpha(),\
				pygame.image.load("z2/z21.png").convert_alpha(),\
				])
		elif num==3:
			self.images.extend([\
				pygame.image.load("z3/z1.png").convert_alpha(),\
				pygame.image.load("z3/z2.png").convert_alpha(),\
				pygame.image.load("z3/z3.png").convert_alpha(),\
				pygame.image.load("z3/z4.png").convert_alpha(),\
				pygame.image.load("z3/z5.png").convert_alpha(),\
				pygame.image.load("z3/z6.png").convert_alpha(),\
				pygame.image.load("z3/z7.png").convert_alpha(),\
				pygame.image.load("z3/z8.png").convert_alpha(),\
				pygame.image.load("z3/z9.png").convert_alpha(),\
				pygame.image.load("z3/z10.png").convert_alpha(),\
				pygame.image.load("z3/z11.png").convert_alpha(),\
				pygame.image.load("z3/z12.png").convert_alpha(),\
				pygame.image.load("z3/z13.png").convert_alpha(),\
				pygame.image.load("z3/z14.png").convert_alpha(),\
				pygame.image.load("z3/z15.png").convert_alpha(),\
				])
		self.image = self.images[self.order]
		self.rect=self.image.get_rect()
		self.rect.top = bg_size[1]-280
		self.rect.left =randint(bg_size[0]*1.5,bg_size[0]*3)
		self.mask=pygame.mask.from_surface(self.image)
		self.energy=Zombie.energy
	def move(self):
		if self.rect.left>0:
			self.rect.left-=self.speed
			if self.rect.left<900 :
				self.rect.top+=self.moveup*0.025
				if self.rect.top<350 or self.rect.top>700 :
					self.moveup=0
	def update(self,passed_time):
		self.passed_time += passed_time
		self.order = (self.passed_time / self._rate )%self._number
		if self.order == 0 and self.passed_time > self._rate:
			self.passed_time = 0
		self.image = self.images[int(self.order)]
#僵尸一号
class Zombie1(Zombie):
	images=[]
	_energy=8
	def __init__(self,bg_size):
		Zombie.__init__(self,bg_size,12,1)

#僵尸二号
class Zombie2(Zombie):
	images=[]
	_energy=8
	def __init__(self,bg_size):
		Zombie.__init__(self,bg_size,21,2)

#僵尸三号
class Zombie3(Zombie):
	images=[]
	_energy=8
	def __init__(self,bg_size):
		Zombie.__init__(self,bg_size,15,3)


class sun(pygame.sprite.Sprite):
	def __init__(self,position):
		pygame.sprite.Sprite.__init__(self)
		self.image = pygame.image.load("sun.png").convert_alpha()
		self.life = 3
		self.speed=0.0001
		self.rect=self.image.get_rect()
		self.active=True
		self.rect.left,self.rect.top = position
		self.flag=0
	def move(self,speed):
		self.rect.top-=speed
		if self.rect.top < 101:
			self.active=False
class yes(pygame.sprite.Sprite):
	def __init__(self,position):
		pygame.sprite.Sprite.__init__(self)
		self.image = pygame.image.load("yes.png").convert_alpha()
		self.life = 3
		self.rect=self.image.get_rect()
		self.active=True
		self.rect.left,self.rect.top = position
		self.flag=0














