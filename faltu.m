clear;clc;close all;
I=imread('prune.tif');
figure,imshow(I);
[m1,n1]=size(I);
se(:,:,1)=[0,0,0;0,1,0;2,1,2];
se(:,:,2)=[1,0,0;0,1,0;0,0,0];
[m,n,l]=size(se);
J=I;U=I;
%c=0;
for q=1:3
    k=1;
    for t=1:8
        
        J=thin(J,se(:,:,k));
    %     if(J==M)
    %         c=c+1;
    %         if(c>8)
    %             break;
    %         end
    %     else
    %         c=0;
    %     end
        tem=se;
        if(t>=4)
            k=2;
        end
        if(t~=4)
            for i=1:m
                for j=1:n   
                    se(j,n+1-i,k)=tem(i,j,k);
                end
            end
        end
        %figure,imshow(J);
    end
    %figure,imshow(J);
    
    T=U-J;match=0;U=J;
    %figure,imshow(T);
    for i1=2:m1-1
        for j1=2:n1-1
            if(T(i1,j1)==1)
                match=0;
                for i2=-1:1
                    for j2=-1:1
                        
                        if(~(i2==0 && j2==0))
                            if(T(i1+i2,j1+j2)==1)
                                J(i1,j1)=true;match=1;
                                T(i1+i2,j1+j2)=0;
                                break;
                            end
                        end
                        
                    end
                    if(match==1)
                        break;
                    end
                end
            end
            
        end
    end
   %figure,imshow(J);         
end
figure,imshow(J);
[m1,n1]=size(J);k=1;
K(1:m1,1:n1)=false;
for t=1:8
    temp=pat_dec(J,se(:,:,k));
    K=union(K,temp);
    tem=se;
    if(t>4)
        k=2;
    else
        k=1;
    end
    for i=1:m
        for j=1:n   
            se(j,n+1-i,k)=tem(i,j,k);
        end
    end
end
figure,imshow(K);
se2=true(3,3);
for t=1:3
    temp2=dil_m(K,se2);
    K=intersection(temp2,I);
end
figure,imshow(K);
L=union(J,K);
figure,imshow(L);