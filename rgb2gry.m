clear;
close all;
I = imread('football.jpg');
figure,imshow(I);
[m n l]=size(I);
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