clear;
a=imread('onion.png');
[m n r]=size(a);
b1=imnoise1('gaussian',m,n,0.5,.1);
a1=rgb2gray(a);
a2=im2double(a1);
c1=(a2).*(b1);
subplot(2,2,1)
imhist(a2);

subplot(2,2,2);
imhist(b1);
title('histogram of gaussian noise');
subplot(2,2,3);
imshow(c1);
title('noisy image due to gaussian noise');
subplot(2,2,4);
imhist(c1);
title('histogram of gaussian noisy image');

for i=2:m-1
    for j=2:n-1
%         d1=double(sum(sum(1./(c1(i-2:i+2,j-2:j+2)))));
%         f(i,j)=double((25/d1));
            d1=(max(max(c1(i-1:i+1,j-1:j+1))));
            d2=(min(min(c1(i-1:i+1,j-1:j+1))));
            d=(d1+d2)/2;
            f(i,j)=d;
    end
end
figure
subplot(1,2,1);
 f1=im2double(f);
imshow(f1);
title('midpoint filtered image');
subplot(1,2,2)
imhist(f1);
title('histogram of filtered image');