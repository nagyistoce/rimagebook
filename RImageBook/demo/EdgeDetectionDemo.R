text <- readImage(system.file("images/text.bmp", package="RImageBook"))
textb <- EBI2biOps(text)             # biOps�`���ɕϊ�
textbedge <- imgPrewitt(textb)       # ����������������Prewitt�t�B���^��K�p
plot(textbedge)
 
textedges <- imgSobel(textb)
plot(textedges)
 
textedgem <- imgMarrHildreth(textb, 3)
plot(textedgem)
 
textedgec <- imgCanny(textb, 2)
plot(textedgec)
 
 