# 笔记储存

这里将储存我的所有与计算机学习相关的markdown笔记

# 开始

[bilibili收藏夹](https://space.bilibili.com/17813457/favlist) / [bilibili-桃子鱼仔ukulele教室](https://space.bilibili.com/90906099)

[知乎收藏夹](https://www.zhihu.com/people/lin-shao-qin-32/collections)

[iCloud](https://www.icloud.com/)

[AnywhereAnything](http://lackar.com/aa/?utm_source=mindstore.io)

## 给儿子的一封信（2019.10.17.）

亲爱的儿子：

你好！在上个月你20周岁生日前，妈妈问你喜欢什么生日礼物，你说写一封信就好！说实在，爸爸妈妈很感动。遗憾的是，虽然一直都有很多话想和你说，因忙于工作琐事，这学期连视频的次数也少很多，更没有静下心来写这封信。

昨天晚上你八点多下课，和你微信视频聊了一会儿，听到你平时早起跑步，让自己一天更有精气神，知道自己在哪里学习效率会更高，周末也有半天时间去打今年选修的棒球，劳逸结合又锻炼身体，爸爸也很高兴，“为国家健康工作五十年”，就像老话说的，身体是革命的本钱！

当我们聊到专业课啊英语啊进实验室啊国外学习时，你说成绩好自然就有很多机会，觉得自己成绩不够好。就这个话题，爸爸和你聊一聊。

儿子，进入大学，特别是上交这样的顶尖学府，学业依然很重，爸爸能感受到你们学习生活的紧张繁重，作为学生，圆满完成学习任务是每个人理所当然的责任。大学学习和高中按部就班的学习形式很不一样，需要我们这个环境里去调整和适应--更自律和更高效的时间管理，但这一点，爸爸相信你，自己能够做好，才大二开始，还不晚，还有时间。爸爸想对你说的是，名校高手如林，我们不用和别人攀比，每个人都有自己的闪光点和使命，我们只要做好自己，今天比昨天好一点，这次比上次好，现在比过去好就可以了。虽说竞争无处不在，但并不都是零和游戏，一起成长、合作、包容、共赢，这样的理念和心态，现代社会尤其重要。

所以，让自己每一天，充实地过而不是虚度时光，过有意义的人生。不管是上课、作业、休息、活动、娱乐、运动、业余爱好、音乐、美食甚至恋爱等等，都可以，只要不浪费青春年华！不用太在意结果，我们不一定做轰轰烈烈的事情，但即使再平凡的小事，只要坚持去做，一定会让自己拒绝走向平庸而会有不平凡的经历和成果！
爸爸更希望你快乐！为自己每一天忙碌的身影、坚定的脚步、不断学到的知识、不断开阔的视野、思维的成长和心灵的感悟，校园里美丽的风景，同学的友谊，老师的教诲......

多去发现和感受周围的真、善、美，重要的是融入这里面，成为更加美好的自己，成为你理想中的“兰彻”！

今天先写到这。改天再聊。

祝儿子每天充实，快乐！拥有更多的真善美！
                                                  
爱你的爸爸

十月十七日夜与家中


## 记录笔记的目的是什么？

是为了更好的理解一件事，是为了能不断回忆，温故而知新，是为了养成习惯，更好的约束自己，提升自己。

## 那么记录笔记的要点又是什么呢？

保持简洁明了。记录方式简洁（网页github、goodnote）；分类方式简洁（学习工作、生活）

其次，要不断浏览，修改和归档

## 那么多信息，那么多需要记录的东西，要如何记录和储存呢？

记录：GitHub.com + goodnote

储存：GitHub + iCloud （从印象笔记迁移）



## 最后，将所有的电子设备同步起来

尽量使用苹果自带应用

## git 使用

``` terminal
$ pwd
/Users/michael/learngit 
$ git init
Initialized empty Git repository in /Users/michael/learngit/.git/

$ git add readme.txt
$ git commit -m "wrote a readme file"
[master (root-commit) eaadf4e] wrote a readme file
 1 file changed, 2 insertions(+)
 create mode 100644 readme.txt
$ git status
On branch master
nothing to commit, working tree clean

$ git reflog
e475afc HEAD@{1}: reset: moving to HEAD^
1094adb (HEAD -> master) HEAD@{2}: commit: append GPL
e475afc HEAD@{3}: commit: add distributed
eaadf4e HEAD@{4}: commit (initial): wrote a readme file
$ git reset --hard 1094a
HEAD is now at 83b0afe append GPL

$ git push origin master
$ git clone git@github.com:michaelliao/gitskills.git
Cloning into 'gitskills'...
remote: Counting objects: 3, done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 3
Receiving objects: 100% (3/3), done.

```
![图示](https://www.liaoxuefeng.com/files/attachments/919020037470528/0)

多人协作的工作模式通常是这样：

1. 首先，可以试图用`git push origin <branch-name>`推送自己的修改；

2. 如果推送失败，则因为远程分支比你的本地更新，需要先用`git pull`试图合并；

3. 如果合并有冲突，则解决冲突，并在本地提交；

4. 没有冲突或者解决掉冲突后，再用`git push origin <branch-name>`推送


## markdown语法

### 标题与等级

***字体字形***

> 引用

分隔符


* 列表
1. 列表

[(链接）Markdown基本语法](https://www.jianshu.com/p/191d1e21f7ed)

[Mastering Markdown](https://guides.github.com/features/mastering-markdown/)

[Mastering Markdown](https://guides.github.com/features/mastering-markdown/)
