clc;
clear all;
close all;
a = imread('cameraman.tif');
subplot(2,2,1);
imshow(a),title('image 1');
[p,q,r]=svd(double(a));
subplot(2,2,2);
semilogy(diag(q)),title('Logplot of singular values of image 1');
a1 = imread('new1.bmp');
subplot(2,2,3);
imshow(a1),title('Image 2');
[p1,q1,r1]=svd(double(a1));
subplot(2,2,4);
semilogy(diag(q1)),title('Logplot of singular values of image 2');
[m,n]=size(a);
b=zeros(size(a));
k=input('enter value of k(largest singular value)=');
for j=1:k
    b=b+q(j,j)*p(:,j)*(r(:,j)).';
end
b=floor(b);
cr=(m*n)/(k*(m+n-1));
figure,imshow(uint8(b)),title(['Reconstructed image with k=',num2str(k),' & Compression Ratio=',num2str(cr),]);
