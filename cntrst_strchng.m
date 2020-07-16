clear;
close all;
l=256;
r1=l/2;s1=l/32;
r2=230;s2=230;
m1=s1/r1;
m2=(s2-s1)/(r2-r1);
m3=(l-1-s2)/(l-1-r2);
I=imread('fig2.tif');
figure,imshow(I);
[m n]=size(I);
for i=1:m;
    for j=1:n;
        x=I(i,j);
        if(x<=r1)
            J(i,j)=0+(m1*(x-0));
        elseif(x>r1 && x<=r2)
            J(i,j)=s1+(m2*(x-r1));
        else
            J(i,j)=s2+(m3*(x-r2));
        end
    end
end
figure,imshow(J);
figure,imhist(I);
figure,imhist(J);