 %%
clear;
d1=imread('football.jpg');
%d1=double(i);
d=im2double(d1);
[m n r]=size(d1);
I=(d(:,:,1)+d(:,:,2)+d(:,:,3))./3;
for t=1:m
    for t1=1:n
        min1(t,t1)=min(d(t,t1,:));
        s1(t,t1)=(min1(t,t1)/I(t,t1));
   
    end
end
s=ones(m,n)-s1;

rmg= d(:,:,1)-d(:,:,2);
rmb= d(:,:,1)-d(:,:,3);
gmb= d(:,:,2)-d(:,:,3);

r1=rmg+rmb;
r2=rmg.*rmg+rmb.*gmb;
r3=sqrt(r2);

for t=1:m
    for t1=1:n
        if r3(t,t1)==0
            r3(t,t1)=0.01;
        end
    end
end
a=0.5.*(r1./r3);
   

tht=acosd(a);

    for t=1:m
        for t1=1:n
            if( d(t,t1,3)>d(t,t1,2)) 
                H=360-tht;
            else
                H=tht;
            end
        end
    end
    
 fil(:,:,1)=H./360;
 fil(:,:,2)=s;
 fil(:,:,3)=I;
%  fi(:,:,1)=fil(:,:,1)*255;
%  fi(:,:,2)=fil(:,:,2)*255;
%  fi(:,:,3)=fil(:,:,3)*255;
 fi=im2double(fil);
 figure,imshow(fil);
 figure,imshow(fi);
