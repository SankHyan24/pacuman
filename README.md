# 😄🎮PaKuMan - 吃豆人
WINDOWS下, C语言编写. 基于libgraphics和浙江大学simplegui写出的新版吃豆人，（实际是浙大大一C大程作业），致敬南梦宫和暴雪娱乐，仅用于教学和交流.

<img src="https://s2.loli.net/2022/02/23/UrH5iJRlMpFDQ4I.png" alt="image-20220223000111783" style="zoom: 50%;" />

## 使用方法:

### 方法一，下载现成的

[下载release版本](https://github.com/SankHyan24/pacuman/releases/), 点击 PacMan.exe 进行游戏.

### 方法二，自行构建

首先下载源代码，然后自行构建

```shell
git clone https://github.com/SankHyan24/pacuman.git
cd pacuman
mkdir build
cd build
cmake ..
make
```

构建程序会自动复制地图到游戏目录下

## 游戏操作:

- 开始界面下，会显示“开始游戏”、“Top10排行榜”、“帮助”、“退出”四个选项。在靠上方的“Edit Name”栏中，你可以自定义自己的名字，使你的大名能留在排行榜中。

<img src="https://s2.loli.net/2022/02/23/gp4uxeVFYHzsOjZ.png" alt="image-20220223000554985" style="zoom:50%;" />

- 首先进入游戏。如果第一次开始游戏，会先进入帮助界面，阅读完游戏介绍即可来到游戏界面。

<img src="https://s2.loli.net/2022/02/23/lz8fNPrq4VAwkTi.png" alt="image-20220223001116885" style="zoom:50%;" />

- 游戏界面中，选择想要使用的人物(每个人物都有他特定的技能)和想要玩的地图(当然,内置的地图编辑器，可以让你自己随心所欲创作地图).

<img src="https://s2.loli.net/2022/02/23/q3d2HubkngPMyeQ.png" alt="image-20220223001239703" style="zoom:50%;" />

- “Map Editor”是地图编辑器，选择好你想自定义的地图之后，点击“Map Editor”即可自定义地图。按界面下方提示的方法操作，可以改变光标闪烁位置的地图信息.

<img src="https://s2.loli.net/2022/02/23/1CzEgWi4TOpbaGr.png" alt="image-20220223001428694" style="zoom:50%;" />

- 选择完毕后, 通过上下左右按键来控制吃豆人的方向, 吃掉足够多的豆子, 并与四只不同性格的鬼保持一定距离.

<img src="https://s2.loli.net/2022/02/23/yulToDWUGC4Pr1K.png" alt="image-20220223002258327" style="zoom:50%;" />

- 游戏中的两个人物具有可释放的技能, 左侧能量栏会记录你的技能能量(如果你的人物有技能的话).如果能量栏满且在闪烁状态, 你便可以按下空格键释放技能. 吃掉豆子可以帮助你重新恢复能量.


<img src="https://s2.loli.net/2022/02/23/bpf9MHUcF3yYNgD.png" alt="image-20220223002112534" style="zoom:50%;" />

- 游戏中右侧是你的游戏进度栏, 你会在游戏进度栏满条时获得胜利.

<img src="https://s2.loli.net/2022/02/23/8OQr5FjBT2XVz7m.png" alt="image-20220223002540590" style="zoom:50%;" />

- 享受游戏带来的乐趣吧! 

**注意:** Release解压后的目录下中的文件, 其中lv1~7的pmm文件均为游戏地图的文本文件, 删除后游戏将不能正确运行; rank.dat文件是游戏排行榜的记录文件, 删除将使你失去本地的排名信息!
## Files:
### [demo](https://github.com/SankHyan24/pacuman/tree/master/demo): 演示文件, 内容和最新版本Release相同
### [lib](https://github.com/SankHyan24/pacuman/tree/master/lib): 项目图形库依赖, 包括斯坦福大学graphics库和浙江大学simpleGUI库
### [map](https://github.com/SankHyan24/pacuman/tree/master/map): 游戏中的地图包. 游戏最多支持7张地图, 使用时放在PacMan.exe 程序的相同目录下，否则游戏无法正常打开. 
### [report](https://github.com/SankHyan24/pacuman/tree/master/report): 大作业上交的项目个人报告pdf以及tex源码
### [sourcecode](https://github.com/SankHyan24/pacuman/tree/master/sourcecode): 项目源代码. 由于只让用C在DevC上写, 所以只用了C
## 关于bug
很遗憾, 由于作者能力有限, 游戏存在一个奇怪的bug. 游戏有一定可能会在超过第二次的冒险中出现秒退的情况. 具体原因可能与所使用的图形库有关. 作者弄不懂图形库, 只会用, 而且懒，所以至今没找到哪里出了问题.
