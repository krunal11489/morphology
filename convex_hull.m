clear;clc;close all;
X=imread('convex.tif');
se=[1,2,2;1,0,2;1,2,2];
[m,n]=size(se);
for k=1:4
    Y=X;M=X;
    while(1)
        N=pat_dec(Y,se);
        %figure,imshow(N);
        Y=union(N,M);
        if(Y==M)
              break;
        end
        M=Y;
        %figure,imshow(Y);
    end
    D(:,:,k)=Y;
    tem=se;
    for i=1:m
        for j=1:n   
            se(j,n+1-i)=tem(i,j);
        end
    end
    figure,imshow(Y);
end
[m,n]=size(X);
Z(1:m,1:n)=0;
for k=1:4
    Z=union(Z,D(:,:,k));
end
figure,imshow(Z);