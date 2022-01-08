# 😄🎮PaKuman - 吃豆人
WINDOWS下, C语言编写. 基于libgraphics和浙江大学simplegui写出的新版吃豆人，仅用于教学和交流.
## 使用方法:
[下载release版本](https://github.com/SankHyan24/pacuman/releases/), 点击 PacMan.exe 进行游戏.
## 游戏操作:
- 首先进入游戏, 选择想要使用的人物(每个人物都有他特定的技能)和想要玩的地图(当然,内置的地图编辑器可以让你自己创作一个地图).
- 选择完毕后, 通过上下左右按键来控制吃豆人的方向, 吃掉足够多的豆子, 并与四只不同性格的鬼保持一定距离.
- 游戏中的两个人物具有可释放的技能, 左侧能量栏会记录你的技能能量.
- 如果能量栏满且在闪烁状态, 你便可以按下空格键释放技能. 吃掉豆子可以帮助你重新恢复能量.
- 游戏中右侧是你的游戏进度栏, 你会在游戏进度栏满条时获得胜利.
- 享受游戏带来的乐趣吧! 

**注意:** Release解压后的目录下中的文件, 其中lv1~7的pmm文件均为游戏地图的文本文件, 删除后游戏将不能正确运行; rank.dat文件是游戏排行榜的记录文件, 删除将使你失去本地的排名信息!
## Files:
### [demo](https://github.com/SankHyan24/pacuman/tree/master/demo): 演示文件, 内容和最新版本Release相同
### [devconfig](https://github.com/SankHyan24/pacuman/tree/master/devconfig): 构建项目时使用的DevC项目配置文件.  不保证有效性.
### [lib](https://github.com/SankHyan24/pacuman/tree/master/lib): 项目图形库依赖, 包括斯坦福大学graphics库和浙江大学simpleGUI库
### [map](https://github.com/SankHyan24/pacuman/tree/master/map): 游戏中的地图包. 游戏最多支持7张地图, 使用时放在PacMan.exe 程序的相同目录下. 
### [report](https://github.com/SankHyan24/pacuman/tree/master/report): 大作业上交的项目个人报告pdf以及tex源码
### [source](https://github.com/SankHyan24/pacuman/tree/master/sourcecode): 项目源代码. 由于只让用C和DevC++来写, 所以只用了C
## 关于bug
很遗憾, 由于作者能力有限, 游戏存在一个奇怪的bug. 游戏有一定可能会在超过第二次的冒险中出现秒退的情况g. 具体原因可能与所使用的图形库有关. 作者弄不懂图形库, 只会用, 所以至今没找到哪里出了问题.
