## Transformação Logarítmo

```cpp
  unsigned char data[]={
10, 30, 80, 150,
140, 210, 90, 80,
230, 60, 40, 70
};

cv::Mat img(3, 4, CV_8UC1, data);
cv::Mat imgAdd50 = img + 50;
```

Este código cria a matriz 

![first equation](https://latex.codecogs.com/svg.image?img=\begin{pmatrix}10&30&80&150\\\\140&210&90&80\\\\230&60&40&70\end{pmatrix})

![](https://latex.codecogs.com/svg.image?imgAdd50=\begin{pmatrix}60&80&130&200\\\\190&255&140&130\\\\255&110&90&120\end{pmatrix}
)

Portanto os pixels com valores acima de 255 serão truncados neste valor.

#### Função Logarítmo
Buscaremos uma função do tipo 

![](https://latex.codecogs.com/svg.image?f(x)=C\times&space;log(1&plus;x))

Onde o parâmetro **C** é determinado de modo que $$f(255)=255$$. Portanto temos:

![](https://latex.codecogs.com/svg.image?C\times&space;log(1&plus;255)=255\Leftrightarrow&space;C=\frac{255}{log(256)})


