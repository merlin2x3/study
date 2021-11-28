from tkinter import*
import math
class Model():
    def __init__(self):
        self.HSA = StringVar()
        self.HSB = StringVar()
        self.D = StringVar()

class FrameOne(Frame):
    def __init__(self, master=None, mode_HSA=None,mode_HSB=None,mode_D=None):
        Frame.__init__(self, master)
        self.frm1=LabelFrame(self)
        self.frm1.pack()
        self.HSA = mode_HSA
        self.HSB=mode_HSB
        self.D = mode_D
        self.init()
        self.Pack()

    def init(self):
        self.lblTitle = Label(self.frm1, text="Máy tính casio",fg="#FF6600",
                              font=("tahoma", 16, 'bold'),justify=CENTER)
        self.lblA=Label(self.frm1,text='Nhập số a: ')
        self.entryA = Entry(self.frm1, width=30, textvariable=self.HSA, bd=5,bg='white')

        self.lblB = Label(self.frm1, text='Nhập số b: ')
        self.entryB = Entry(self.frm1, width=30, textvariable=self.HSB, bd=5,bg='white')

        self.lblC = Label(self.frm1, text='Phép tính: ')
        self.entryC = Entry(self.frm1, width=30, textvariable=self.D, bd=5, bg='white')

    def Pack(self):
        self.lblTitle.grid(row=0, columnspan=2)
        self.lblA.grid(row=1, column=0)
        self.lblB.grid(row=2, column=0)
        self.lblC.grid(row=3, column=0)
        self.entryA.grid(row=1, column=1)
        self.entryB.grid(row=2, column=1)
        self.entryC.grid(row=3, column=1)
class FrameTwo(Frame):
    def __init__(self, master=None, mode_HSA=None,mode_HSB=None,mode_D=None):
        Frame.__init__(self, master)
        self.HSA = mode_HSA
        self.HSB = mode_HSB
        self.D = mode_D
        self.KQ=StringVar()
        self.Show()
        self.Pack()
    def Show(self):
        self.frmButton = Frame(self, borderwidth=2)
        self.btnGiai = Button(self.frmButton, text="Giải", width=10,bg='#666666',
                         fg='white',bd=3,command=self.buttonGiai)

        self.btnTiep = Button(self.frmButton, text="Tiếp", width=10,bg='#666666',
                        fg='white',bd=3, command=self.buttonTiep)

        self.btnThoat = Button(self.frmButton, text="Thoát", width=10,bg='#666666',
                        fg='white', bd=3,command=self.quit)
        self.lblKQ = Label(self, text="Kết quả:")
        self.entryKQ = Entry(self, width=50, textvariable=self.KQ,bd=5,bg='white')

    def Pack(self):
        self.btnGiai.pack(side=LEFT)
        self.btnTiep.pack(side=LEFT)
        self.btnThoat.pack(side=LEFT)
        self.lblKQ.grid(row=4, column=0)
        self.entryKQ.grid(row=4, column=1)
        self.frmButton.grid(row=3, columnspan=2)

    def buttonGiai(self):
        try:
            a = float(self.HSA.get())
            b = float(self.HSB.get())
            c = (self.D.get())
            kq = ""
            if c=='+':
                kq='{}'.format(a+b)
            if c=='-':
                kq='{}'.format(a-b)
            if c=='*':
                kq='{}'.format(a*b)
            if c=='/':
                if b==0: kq=("Khong the chia cho 0 !")
                if b!=0: kq='{}'.format(a/b)

            self.KQ.set(kq)
        except:
            self.KQ.set('Error')

    def buttonTiep(self):
        self.HSA.set("")
        self.HSB.set("")
        self.D.set("")
        self.KQ.set("")

class MainApp(Frame):
    def __init__(self, master=None, model=None):
        Frame.__init__(self, master)
        self.Main()

    def Main(self):
        self.model = Model()
        self.frm1 = FrameOne(self, self.model.HSA,self.model.HSB,self.model.D)
        self.frm1.pack(fill="x")
        self.frm2 = FrameTwo(self, self.model.HSA,self.model.HSB,self.model.D)
        self.frm2.pack(fill="both")
        self.pack(expand=True, fill="both")

class App(Tk):
    def __init__(self):
        super().__init__()
        self.title('Nguyễn Ngọc Đan Trường 15-04')
        self.geometry('320x320')
        self.resizable(0,0)

if __name__ == '__main__':
    app=App()
    MainApp(app)
    app.mainloop()
