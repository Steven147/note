import random
import tkinter


v1 = '@'
v2 = '@'
alphabet1 = "akstnhmyrw"
values1 = range(0,10,1)
alphabet2 = "aiueo"
values2 = range(0,5,1)
show = False
mystr = "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもや0ゆ0よらりるれろわ000を"
mystr2 = "アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤ0ユ0ヨラリルレロワ000ヲ"
#print(alphabet1[v1], alphabet2[v2],mystr[v1*5+v2])

windows = tkinter.Tk()
windows.title('五十音学习')
windows.geometry('150x190')

var = tkinter.StringVar()
l = tkinter.Label(windows, textvariable = var, font=('Arial, 12'), width=15, height=2)
l.pack()

var2 = tkinter.StringVar()
l2 = tkinter.Label(windows, textvariable = var2, font=('Arial, 12'), width=15, height=2)
l2.pack()


def new():
    global v1, v2,values1, values2, show
    valid = False
    while(not valid):
        v1 = random.choice(values1)
        v2 = random.choice(values2)
        #71yi 73ye 91wi 92wu 93we
        if(v1*5+v2 == 36 or v1*5+v2 == 38 or v1*5+v2 == 46 or v1*5+v2 == 47 or v1*5+v2 == 48): pass
        else:
            valid = True;
    if(v1==0):
        var.set(alphabet2[v2])
    elif(v1*5+v2==16):
        var.set('ch'+alphabet2[v2])
    elif(v1*5+v2==16):
        var.set('ts'+alphabet2[v2])
    else:
        var.set(alphabet1[v1]+alphabet2[v2])
    
    if(not show): 
        var2.set('')
    else:
        var2.set(mystr[v1*5+v2]+' '+mystr2[v1*5+v2])

def showResult():
    global v1, v2, mystr
    var2.set(mystr[v1*5+v2]+' '+mystr2[v1*5+v2])

def alwaysShow():
    global show
    if(not show): 
        var3.set('Always Show')
        show = not show
    else:
        var3.set('Not Show')
        show = not show


b = tkinter.Button(windows, text = 'NEW!', width = 15, height=2, command=new)
b.pack()

b2 = tkinter.Button(windows, text = "I don't know!", width = 15, height=2, command=showResult)
b2.pack()

var3 = tkinter.StringVar()
var3.set('Always Show')
b3 = tkinter.Button(windows, textvariable = var3, width = 15, height=2, command=alwaysShow)
b3.pack()





windows.mainloop()




