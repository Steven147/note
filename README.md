# 笔记储存

这里将储存我的所有的markdown笔记

## 开始

[提问的智慧](https://github.com/ryanhanwu/How-To-Ask-Questions-The-Smart-Way/blob/master/README-zh_CN.md)

[(链接）Markdown基本语法](https://www.jianshu.com/p/191d1e21f7ed)

[Mastering Markdown](https://guides.github.com/features/mastering-markdown/)


### 我的文件

|文件类型|储存地址|
|-|-|
|大文件|[iCloud](https://www.icloud.com/)|
|文本文档|[Github-note](https://github.com/Steven147/note)|
|程序文件|[Github-cpp](https://github.com/Steven147/cpp)|
|手写文档|GoodNotes|

### 我的应用

|应用|用途|
|-|-|
|VSCode|文字，代码编辑|
|GoodNotes|手写文本编辑|


### 记录笔记的目的

是为了更好的理解一件事，是为了能不断回忆，温故而知新，是为了养成习惯，更好的约束自己，提升自己。

### 记录笔记的要点？

保持简洁明了。记录方式简洁（网页github、goodnote）；分类方式简洁（学习工作、生活）

其次，要不断浏览，修改和归档

### 信息如何记录和储存？

记录：GitHub.com + goodnote

储存：GitHub + iCloud （从印象笔记迁移）

### 最后，同步

尽量使用苹果自带应用

## git 使用

``` 
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