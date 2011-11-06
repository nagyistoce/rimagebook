bg <- matrix(0, 256, 256)
display(bg)
grad <- matrix(c(0:255)/255, 256, 256)
display(grad)
x <- 0:65535
wave <- matrix(sin(x*pi/63.7), 256, 256)
display(wave)
w <- 256
h <- 256
s <- 40                                           # sigma���w��
fn <- function(x, y, s) exp(-(x^2+y^2)/(2*s^2))   #�@�֐����`
x <- seq(-floor(w/2), floor(w/2), len=w)          # x���W�͈̔�
y <- seq(-floor(h/2), floor(h/2),len=h)           # y���W�͈̔�
w <- outer(x, y, fn, s)                           # ��ʉ��O�ϊ֐�
display(normalize(w))
bg <- matrix(0, 256, 256)                        # �w�i�̍쐬
cr <- drawCircle(bg, 100, 100, 50, 1)            # �~����`��
cr <- drawCircle(cr, 160, 160, 20, 1, fill=TRUE) # �h��Ԃ����~��`��
display(cr)
theta <- seq(0, 2 * pi, length=(100))
x <- 200 + 100 * cos(theta)
y <- 200 + 30 * sin(theta)
plot(x, y, type = "l")
par(plt=c(0, 1, 0, 1), xaxs="i", yaxs="i") # ��}�ݒ��ύX
theta <- seq(0, 2 * pi, length=(100))
x <- 200 + 100 * cos(theta)
y <- 200 + 30 * sin(theta)
                                           # �o�͐��png�t�@�C���ɐݒ�
png(filename = "temp.png", width = 400, height = 400, bg = "black")
plot(x, y, type = "l", axes=F, col="white", xlim=c(0, 400), ylim=c(0, 400))
dev.off()                                  # �t�@�C���ւ̏o�͂�����
img <- readImage("temp.png")               # �o�͂����t�@�C����ǂݍ���Ŋm�F
display(img)
library("shape")
par(plt=c(0, 1, 0, 1), xaxs="i", yaxs="i")
png(filename = "temp.png", width = 400, height = 400, bg = "black")
emptyplot(xlim = c(0, 400), ylim = c(0, 400))
filledellipse(rx1 = 100, ry1 = 200, mid = c(200, 200), 
              angle = 30, col = "white")
filledellipse(rx1 = 100, ry1 = 100, rx2 = 50, ry = 50, 
              mid = c(200, 200), col = "gray")
dev.off()
img <- readImage("temp.png")
display(img)