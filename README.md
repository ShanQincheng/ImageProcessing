# 前言
演算法分析的機測題目，要求用 OpenCV 函式庫，實現圖像的紋理合成。此文章介紹在實現紋理合成前，用 OpenCV 函式庫對圖像的基本操作。

***

# 環境
    IDE           Visual Studio 2017
    platform      x64，windows
    language      C, openCV
  
***

# 開始
* 1、OpenCV 庫導入 VS2017 的方法
* 2、理論基礎
* 3、OpenCV 介紹
* 4、圖像讀取、顯示、存儲 程式設計
* 5、圖像拼接 程式設計

**版權聲明：** **理論基礎**， **OpenCV 介紹** 這兩部分內容，均直接摘抄自我的演算法分析老師，中原大學張元翔，2017 演算法分析課程，第二次機測說明文件中。

***

###1、OpenCV 庫導入 VS2017 的方法
將 OpenCV 庫下載後並能在 IDE 中正常調用，需要進行一些配置。配置的方法有人已經寫的很好了，直接附上鏈接。

[ Win10 VS2017下OpenCV3.2配置](http://blog.csdn.net/qq_25729757/article/details/63344004)

***

###2、理論基礎
**影像 (Digital Image)** 可以定義為二維函數： 

                                          f( x,y )
 
其中 ( x, y ) 稱為**空間座標 (Spatial Coordinate)**， f 的大小稱為**強度 (Intensity)** 或**灰階 (Gray Level)**。當 x、 y 與 f 均為有限的離散值時，則影像稱為**數位影像  (Digital Image)**。 
 
典型的數位影像， 如圖所示，稱為 **Lenna** 影像，是影像處理技術相關研究領域經常使用的數位影像。數位影像是由許多基本元素( 或點 )所構成，這些基本元素稱為**像素( Pixels )**。**像素( Pixels )** 其實是源自 **Picture Elements** 的英文，其中 cture 以 x 取代縮寫而得。空間座標經常 以**列 ( Rows )** 與 **行 ( Columns )** 表示，因此數位影像包含 M 列 × N 行像素。影像的左上角為原點，座標為  ( 0, 0 )，右下角的座標為 （ M - 1, N - 1 ） 。
![](/content/images/2017/05/QQ--20170528174428-1.png)
數位影像中每一個像素的灰階值通常是選取固定的階數L，且L為 2 的冪次方，即： 

                                            L = 2ⁿ
通常每個像素是以 8 位元 ( n = 8 ) 儲存，即 L = 2^8 = 256 ，代表共有 256 個灰階，其值介於 0 ~ 255 之間；0 代表黑色，255 代表白色。以下為局部區域範例： 
![](/content/images/2017/05/QQ--20170528174843.png)
數位影像可以分成**灰階影像( Gray-Level Image )**與**彩色影像( Color Image )**，如下圖所示。 以彩色影像而言，每個像素則包含 **R、G、B**( 即光的三原色，分別為紅、綠、藍色 )。**R、G、 B** 又稱為**通道( Channel )**，因此灰階影像又稱為單通道影像，彩色影像則稱為三通道影像。通常，彩色影像中每個像素是以 **24-bits**( 即每個通道各佔 8-bits ) 存取。 
![](/content/images/2017/05/QQ--20170528175116.png)

***
###3、OpenCV 介紹
OpenCV 為**開源電腦視覺程式庫( Open Source Computer Vision Library )** 的縮寫，其中包 含：影像處理、視訊處理、機器學習、…等相關技術。由於 OpenCV 程式庫為 BSD 授權，屬 於自由軟體，同時提供許多開放原始碼，可供學術界與產業界免費使用，目前已被廣泛應用 於許多不同的領域。

OpenCV 定義了一組資料型態，可以用來處理不同的資料型態，如下表。其中，OpenCV 主要是使用 Mat ( Matrix 矩陣 ) 的資料結構存取數位影像。 
![](/content/images/2017/05/QQ--20170528175400.png)

***
###4、圖像讀取、顯示、存儲 程式設計
使用 C++語言與 OpenCV 顯示數位影像 (Mat 資料結構) 的程式範例如下： 
```
/* 
 Display Image using C++ & OpenCV 
*/
#include "stdafx.h"
#include <iostream> 
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat img = imread("Image.jpg");
    namedWindow("Image", WINDOW_AUTOSIZE);   
    imwrite("outPut.jpg", img);
    imshow("Image", img);
    waitKey(0);

    return 0;
}
```

程式碼分別說明如下： 

* 第 1 ~ 3 行 /* */ 表示註解。  
* 第 4, 6 行 加入 OpenCV 的基本程式庫，包含 iostream 與 opencv。在此，opencv 將包含 OpenCV 程式庫提供的所有函式。在此也可僅加入需要的程式庫。
* 第 8, 9 行 使用命名空間 std 與 cv，即標準輸入/輸出與 OpenCV 基本的命名空間。
* 第 11 行 main 代表程式主體。 
* 第 12 行 宣告 Mat 數位影像物件，數位影像的名稱為 img，imread 函式則進行影像的讀取並配置記憶體空間。 
* 第 13 行 開啟視窗，名稱為 Image，WINDOW_AUTOSIZE 表示視窗大小將依影像大小**自動調整**。 
* 第 14 行 將讀取的數位圖像 "Image.jpg"， 存儲到與當前程式碼相同的資料夾，命名為 outPut.jpg
* 第 15 行 於 Image 視窗中顯示數位影像 img。 
* 第 16 行 等待使用者輸入，0 表示持續等待直至使用者鍵入任意鍵再繼續往下執行。 
* 第 18 行 回傳值。 
![](/content/images/2017/05/QQ--20170528181804.png)
當載入的影像為色彩影像時，則資料型態為 CV_8U，其中 8U 代表使用 unsigned char 的資料型態 ( 8 bits )，共有 R、G、B 三個通道。下列指令為讀取數位影像在 ( x, y ) 座標的像素色彩值： 
```
Vec3b RGB = img.at<Vec3b>( x, y ) ; 
    uchar blue  = RGB.val [0] ; 
    uchar green = RGB.val [1] ; 
    uchar red   = RGB.val [2] ; 
```


***
### 5、圖像拼接 程式設計
現在我想載入兩張金三胖的圖片，然後把這兩張圖片橫向拼接成一張圖片。
####思路
* 從硬碟中讀取兩張金三胖的圖片，分別賦給兩個 Mat 數位影響物件 kim1, kim2
* 獲取 kim1， kim2 的 rows number 和 cols number，以確定金三胖圖片的大小，即像素個數。
* 創建一個 Mat 數位影響物件 kimCreate ，為其分配 kim1 + kim2 的空間，因為要把 kim1 和 kim2 合成一張圖片
* 把 kim1 、 kim2 中的像素以從上到下，自左而右的順序，通過 Vec3b 這種資料形態 ，賦值給 kimCreate。
* 顯示 kimCreate。

####需要用到的函數

* **Mat.create(int rows, int columns, int_type Mat_Type);**  
 給 Mat 物件分配 rows * columns 大小的空間，即創建一個 rows * columns 的新圖像。該圖像的種類為 Mat_Type
* **（int） Mat.rows;**  
返回該圖像的 rows number
* **（int） Mat.cols;**   
返回该图像的 cols number

```
#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(int argc, char** argv) {
        Mat kim1 = imread("Image.jpg");   // read kim picture from file
		Mat kim2 = imread("Image.jpg"); // read kim picture from file
		int rows = kim1.rows;  // get rows number from kim picture
		int cols = kim1.cols;  // get cols number from kim picture
		int i = 0; // iterator variable
		int j = 0; // iterator variable

		Mat kimCreate;  // declare synthesis picture
		kimCreate.create(rows, 2 * cols, CV_8UC3); // allocate memory for it
        // create a show window and name it with "Kim  copyRight: codingstory"
		namedWindow("Kim  copyRight: codingstory", WINDOW_AUTOSIZE); 

    /*
        assign each pixel value in (Mat)kim1 to (Mat)kimCreate 
        according to the pixel type of Vec3b
    */
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				Vec3b RGB = kim1.at<Vec3b>(i, j);
				kimCreate.at<Vec3b>(i, j) = RGB;
			}	
		}
    /*
        append each pixel value in (Mat)kim2  to (Mat)kimCreate 
        according to the pixel type of Vec3b
    */
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				Vec3b RGB = kim2.at<Vec3b>(i, j);
				kimCreate.at<Vec3b>(i, j + cols) = RGB;
			}
		}
		/*
                show the rows and cols of kim picture
       */
		cout << "ROWS: " << rows << endl;
		cout << "COLS: " << cols << endl;

        // show the synthesis picture on the windows      
		imshow("Kim  copyRight: codingstory", kimCreate); 
        // keep the picture showing on the screen until user input some key
		waitKey(0);

		return 0;
	}
```
![](/content/images/2017/05/QQ--20170528190228.png)

***
#以上
2017 年 5 月 28 日
