clear;
close all;
I = imread('football.jpg');
figure,imshow(I);
[m,n,l]=size(I);
for i=1:m;
    for j=1:n;
        temp=0;
        for k=1:l;
            temp=temp+(I(i,j,k)/3);
        end
        J(i,j)=uint8(temp);
    end
end
figure,imshow(J);
a=45;
t=(a*pi)/180;
J1(:,:)=0;
for i=1:m;
    for j=1:n;
        x=(i*cos(t))-(j*sin(t));
        y=(i*sin(t))+(j*cos(t));
        J1(x,y)=J(i,j);
    end
end
figure,imshow(J1);
            