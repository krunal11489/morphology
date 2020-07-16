close all;
a1=imread('fig2.tif');
[m n]=size(a1);
% a1=rgb2gray(a);
c(1:256)=0;

for i=0:m-1
    for j=0:n-1
        k=a1(i+1,j+1);
        c(k+1)=c(k+1)+1;
    end
end

c1=c./(m*n);

s(1:256)=0;
s(1)=255*c(1);
for i=1:255
    s(i+1)=255*c1(i+1)+s(i);
end

sin1=uint8(s);

for i=1:m
    for j=1:n
        k=a1(i,j);
        b(i,j)=sin1(k);
    end
end
imshow(b);
c2(1:256)=0;

for i=0:m-1
    for j=0:n-1
        k=b(i+1,j+1);
        c2(k+1)=c2(k+1)+1;
    end
end
figure;
stem((0:255),c2);
figure;
stem(c);
