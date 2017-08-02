import pygame
import sys
import wave
import traceback
import material
from pygame.locals import *
from random import *

pygame.init()
pygame.mixer.init()

bg_size=width,height=1136,768

#加载声音
pygame.mixer.music.load("music.wav")
pygame.mixer.music.set_volume(0.2)
use_bomb_sound = pygame.mixer.Sound("use_bomb.wav")
use_bomb_sound.set_volume(0.2)

#载入文字
score_font=pygame.font.Font("font/font.ttf",36)
screen = pygame.display.set_mode(bg_size)
pygame.display.set_caption("植物大战僵尸")

#载入图片
select1=pygame.image.load("select1.png").convert_alpha()
select2=pygame.image.load("select2.png").convert_alpha()
sun = pygame.image.load("sun.png").convert_alpha()
yes=pygame.image.load("yes.png").convert_alpha()
over1=pygame.image.load("overlose.png").convert_alpha()
over2=pygame.image.load("overwin.png").convert_alpha()

clock=pygame.time.Clock()

BLACK=(0,0,0)
GREEN=(0,255,0)
RED=(255,0,0)
WHITE=(255,255,255)
PURPLE =(0,104,139)


#建立植物组
grass=pygame.sprite.Group()
greengrass=pygame.sprite.Group()
bluegrass=pygame.sprite.Group()
fungus=pygame.sprite.Group()
bomb=pygame.sprite.Group()

#建立僵尸组
zombies=pygame.sprite.Group()
zombies1=pygame.sprite.Group()
zombies2=pygame.sprite.Group()
zombies3=pygame.sprite.Group()
suns = []
score=0
zombies_n=0
zombies_num=0
green1=0
blue1=0
fungus1=0
bombs1=0
f=0
#增加僵尸一号
def add_zombie1(group1,group2,num):
	for i in range(num):
		e=material.Zombie1(bg_size)
		group1.add(e)
		group2.add(e)
#增加僵尸二号
def add_zombie2(group1,group2,num):
	for i in range(num):
		e=material.Zombie2(bg_size)
		group1.add(e)
		group2.add(e)
#增加僵尸三号
def add_zombie3(group1,group2,num):
	for i in range(num):
		e=material.Zombie3(bg_size)
		group1.add(e)
		group2.add(e)
#增加植物一号
def add_greengrass(group1,group2,num):
	for i in range(num):
		e=material.GreenGrass()
		group1.add(e)
		group2.add(e)
#增加植物二号
def add_bluegrass(group1,group2,num):
	for i in range(num):
		e=material.BlueGrass()
		group1.add(e)
		group2.add(e)
#增加植物三号
def add_fungus(group1,group2,num):
	for i in range(num):
		e=material.Fungus()
		group1.add(e)
		group2.add(e)
#增加植物四号
def add_bomb(group1,group2,num):
	for i in range(num):
		e=material.Bomb()
		group1.add(e)
		group2.add(e)

#检测碰撞
def CheckBullet(delay): 
	global zombies_n
	global zombies
	for each in grass:
		if not (delay%50):
			each.bullet_move()
		for b in each.bullet:
			if b.active and zombies_n and each.active:
				b.move(each.rect.left)
				screen.blit(b.image,b.rect)
				bullet_hit=enemy_hit=pygame.sprite.spritecollide(b,zombies,False,pygame.sprite.collide_mask)
				if bullet_hit:
					for e in bullet_hit:
						if e.active and b.active:
							b.active=False
							if each.sign==1:
								e.energy-=2
							if each.sign==2:
								e.moving=False
							if each.sign==3:
								e.energy-=1
							if each.sign==4:
								e.energy-=e.energy
						print(e.energy )
def CheckZombie(delay):
	global zombies_n
	global zombies_num
	global grass
	global zombies
	global suns
	for each in zombies:
		if each.rect.left<=0:
			each.active=False
			
			screen.blit(over1,(0,0))
			pygame.display.flip()
			pygame.quit() 
			sys.exit()
		if each.rect.left<bg_size[0] and each.flag==0:
			zombies_n+=1 #出现在屏幕上的僵尸数目
			each.flag=1
		if each.active:
			if each.hit==False and each.moving:#僵尸未撞击到植物或未被蓝色子弹打中
				each.move()
			if not each.moving:
				each.i+=1
				if each.i>=100:
					each.moving=True
					each.i=0
			each.update(5)
			screen.blit(each.image,each.rect)
			if each.energy<=0:
				each.active=False
				suns.append(material.sun(each.rect.midtop))
			if each.hit:
				each.hit=False
			pygame.draw.line(screen,BLACK,
								(each.rect.left,each.rect.top-5),\
								(each.rect.right,each.rect.top-5),\
							2)
			energy_remain=each.energy/each._energy
			if energy_remain>0.2:
				energy_color=GREEN
			else:
				energy_color=RED
			pygame.draw.line(screen,energy_color,
								(each.rect.left,each.rect.top-5),\
								(each.rect.left+each.rect.width*energy_remain,each.rect.top-5),\
							2)
	for each in grass:
		if not (delay%50):
			each.bullet_move()
		for b in each.bullet:
			if b.active and zombies_n and each.active:
				b.move(each.rect.left)
				screen.blit(b.image,b.rect)
				bullet_hit=enemy_hit=pygame.sprite.spritecollide(b,zombies,False,pygame.sprite.collide_mask)
				if bullet_hit:
					for e in bullet_hit:
						if e.active and b.active:
							b.active=False
							if each.sign==1:
								e.energy-=2
							if each.sign==2:
								e.moving=False
							if each.sign==3:
								e.energy-=1
							if each.sign==4:
								e.energy-=e.energy
def ChectGrass(delay):
	global grass
	global greengrass
	global bluegrass
	global bomb
	global score
	global green1
	global blue1
	global fungus1
	global bombs1
	for event in pygame.event.get():
		if event.type==QUIT:
			pygame.quit()
			sys.exit()
		if event.type == MOUSEBUTTONDOWN:
			for each in grass:
				if each.flag==1 and each.has:
					x, y = pygame.mouse.get_pos()
					if y>125:							
						each.move(x,y)
						each.energy=each._energy
						if green1==1:
							add_greengrass(greengrass,grass,1)
							green1=0
							score-=each._energy
							font_=score_font.render(str(score),False,BLACK)
							screen.blit(font_,(1000,20))							
						if blue1==1:
							add_bluegrass(bluegrass,grass,1)
							blue1=0
							score-=each._energy
							font_=score_font.render(str(score),False,BLACK)
							screen.blit(font_,(1000,20))							
						if fungus1==1:
							add_fungus(fungus,grass,1)
							fungus1=0
							score-=each._energy
							font_=score_font.render(str(score),False,BLACK)
							screen.blit(font_,(1000,20))							
						if bombs1==1:
							add_bomb(bomb,grass,1)
							bombs1=0
							score-=each._energy
							font_=score_font.render(str(score),False,BLACK)
							screen.blit(font_,(1000,20))
						each.flag=0
						each.active=True
					else:
						each.flag=0
						green1=0
						blue1=0
						fungus1=0
						bombs1=0
				elif each.flag==0 and each.has:
					x,y=pygame.mouse.get_pos()
					if each.rect.left< x <each.rect.right and each.rect.top < y <each.rect.bottom:
						if each.rect.top==10 and each.rect.left==220:
							green1=1
						if each.rect.top==25 and each.rect.left==120:
							blue1=1
						if each.rect.top==20 and each.rect.left==10:
							fungus1=1
						if each.rect.top==10 and each.rect.left==320:
							bombs=1
						each.flag=1
	for each in grass:
		enemies_down = pygame.sprite.spritecollide(each,zombies,False,pygame.sprite.collide_mask)
		if each.active:
			each.update(5)
			screen.blit(each.image,each.rect)
		if each.life==0:
			each.active=False
		for e in enemies_down:
			if e.active:
				each.life-=1
				if each.active:
					e.hit=True
		if 10<=each.rect.top<=25 and 10<=each.rect.left <=320:
			if score>=each._energy:
				each.has=True
				screen.blit(yes,(each.rect.left+30,each.rect.top-15))
			else:
				each.has=False
def Suns(delay,have,has):
	global suns
	global score
	for i in range(len(suns)):
		if suns[i].active:
			screen.blit(suns[i].image,suns[i].rect)
			if pygame.mouse.get_pressed()[0]:
				x,y=pygame.mouse.get_pos()
				if suns[i].rect.left<x<suns[i].rect.right and suns[i].rect.top<y<suns[i].rect.bottom:
					suns[i].flag=1
			if suns[i].flag==1:
				suns[i].move(0.5)
				if suns[i].active==False:
					if have==True and has==False:
						for each in grass:
							if each.rect.top==20 and each.rect.left==10:
								each.energy+=1
								if each.energy==each._energy:
									score-=each._energy
									has==True
					score+=1

					font_=score_font.render(str(score),False,BLACK)
					screen.blit(font_,(1000,20))

			elif not delay % 10:
				suns[i].life-=0.1
				if suns[i].life==0:
					suns[i].active=False
def click(x1,x2,y1,y2):
	if pygame.mouse.get_pressed()[0]:
		x,y=pygame.mouse.get_pos()
		if x1<x<x2 and y1<y<y2:
			return True
		else:
			return False
fbegin=False
yeses=[]
fselect=False
l=[0,0,0,0,0,0]
running=False 

def prepare():

	a=False#场景
	b=False#植物
	global yeses 
	global fbegin
	global fselect
	global running
	global l
	if fbegin:
		screen.blit(select2,(0,0))
	for event in pygame.event.get():
		if event.type==QUIT:
			pygame.quit() 
			sys.exit()
		if click(405,705,90,205) and fselect==True:
			running=True
			fbegin=False
			
		elif click(405,705,250,365) and fselect==False:
			fbegin=True
			#选择场景
		elif fbegin:
			if click(40,615,120,400)and l[1]==0:
				if l[0]==0:
					l[0]=1
					yeses.append((320,260))
				else:
					l[0]=0
					yeses.remove((320,260))
			elif click(40,615,420,700)==True and l[0]==0:
				if l[1]==0:
					l[1]=1
					yeses.append((320,560))
				else:
					l[1]=0
					yeses.remove((320,560))
			elif click(740,820,240,330)==True and (l[3]==0 or l[4]==0 or l[5]==0):
				if l[2]==0:
					l[2]=1
					yeses.append((780,280))
				else:
					l[2]=0
					yeses.remove((780,280))
			elif click(960,1045,240,325)==True and (l[2]==0 or l[4]==0 or l[5]==0): 
				if l[3]==0:
					l[3]=1
					yeses.append((1002,280))
				else:
					l[3]=0
					yeses.remove((1002,280))
			elif click(730,820,500,560)==True and (l[2]==0 or l[3]==0 or l[5]==0):
				if l[4]==0:
					l[4]=1
					yeses.append((780,530))
				else:
					l[4]=0
					yeses.remove((780,530))
			elif click(960,1050,490,560)==True and (l[2]==0 or l[3]==0 or l[4]==0):
				if l[5]==0:
					l[5]=1
					yeses.append((1005,525))
				else:
					l[5]=0
					yeses.remove((1005,525))
			if l[0]==1 or l[1]==1:
				a=True
			for i in range(len(l[2:])):
				if l[i]==1:
					b=True
			if click(1010,1115,645,685) and a==True and b==True:
				fselect=True

	if not fselect:
		for i in range(len((yeses))):
			screen.blit(yes,yeses[i])
	if fselect:
		screen.blit(select1,(0,0))
	pygame.display.flip()
	
def main():
	global grass
	global greengrass
	global bluegrass
	global bomb

	global zombies
	global zombies1
	global zombies2
	global zombies3
	global l
	global running
	global score


	global suns

	background=pygame.image.load("grass.jpg").convert_alpha()

	clock.tick(60)
	global zombies_n
	global zombies_num
	score = 0
	screen.blit(select1,(0,0))
	delay=0
	has=False
	have=False
	global f
	while not running:
		prepare()

	if l[0]==1:
		f=1
		background=pygame.image.load("grass.jpg").convert_alpha()
	if l[1]==1:
		f=2
		background=pygame.image.load("ground.jpg").convert_alpha()
	if l[2]==1:
		print("green")
		add_bluegrass(bluegrass,grass,1)
		l[2]=0
	if l[3]==1:
		print("blue")
		add_greengrass(greengrass,grass,1)
		l[3]=0
	if l[4]==1:
		print("purple")
		add_bomb(bomb,grass,1)
		l[4]=0
	if l[5]==1:
		print("bomb")
		add_fungus(fungus,grass,1)
		l[5]=0
	suns.append(material.sun((1000,500)))
	suns.append(material.sun((700,450)))
	suns.append(material.sun((200,300)))
	add_zombie1(zombies1,zombies,2)
	add_zombie2(zombies2,zombies,2)
	add_zombie3(zombies3,zombies,2)
	zombies_num+=6
	pygame.display.flip()
	pygame.mixer.music.play(-1)
	while running:

		font_=score_font.render(str(score),False,BLACK)
		font=score_font.render('sun:', False, BLACK)

		screen.fill(WHITE)
		screen.blit(background,(0,0))
		screen.blit(font,(800,20))
		screen.blit(font_,(880,20))

		CheckZombie(delay)
		ChectGrass(delay)

		for event in pygame.event.get():
			if event.type==QUIT:
				pygame.quit()
				sys.exit()


		Suns(delay,have,has)  
		delay-=1
		if not delay:
			delay=100
		clock.tick(60)
		pygame.display.flip()
if __name__=="__main__":
	try:
		main()
	except SystemExit:
		pass
	except:
		traceback.print_exc()
		pygame.quit()
		input()










				