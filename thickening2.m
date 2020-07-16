clear;close all;clc;
I=imread('thick.tif');
se(:,:,1)=[2,2,2;2,0,2;0,0,0];
se(:,:,2)=[1,1,2;1,0,0;2,0,0];
[m n l]=size(se);
J=I;M=I;
c=0;k=1;
while(1)
    
    M=J;
    J=thick(M,se(:,:,k));
    if(J==M)
        c=c+1;
        if(c>8)
            break;
        end
    else
        c=0;
    end
    tem=se;
    if(k==1)
        k=2;
    else
        k=1;
    end
    for i=1:m
        for j=1:n   
            se(j,n+1-i,k)=tem(i,j,k);
        end
    end
    figure,imshow(J);
end
%K=m_connectivity(J);
figure,imshow(I);
figure,imshow(J);
%figure,imshow(K);
