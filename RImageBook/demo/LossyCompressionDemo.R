## Demo codes for p.15 Fig.2.6
f <- system.file("images/lena.tif", package="RImageBook")
lena <- readImage(f)
writeImage(lena, "lena.png")
writeImage(lena, "lena1.jpg", quality=1)
writeImage(lena, "lena10.jpg", quality=10)
writeImage(lena, "lena50.jpg", quality=50)
writeImage(lena, "lena100.jpg", quality=100)
writeImage(lena, "lena.tiff")
display(readImage("lena.png"), "lena.png")
display(readImage("lena1.jpg"), "lena1.jpg")
display(readImage("lena10.jpg"), "lena10.jpg")
display(readImage("lena50.jpg"), "lena50.jpg")
display(readImage("lena100.jpg"), "lena100.jpg")
display(readImage("lena.tiff"), "lena.tiff")
# Check file size
file.info("lena.tiff")$size
file.info("lena.png")$size
file.info("lena100.jpg")$size
identical(readImage("lena.png"), readImage("lena.tiff"))
