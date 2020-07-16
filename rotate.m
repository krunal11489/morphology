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
for i=1:m;
    for j=1:n;
        x=(i*cos(t))-(j*sin(t));
        y=(i*sin(t))+(j*cos(t));
         J1(i,j)=round(x);
         J2(i,j)=round(y);
    end
end
if(a<=90)
  scl=min(min(J1));
  J1=J1-scl+1;
elseif(a>90 && a<=180)
    scl=min(min(J2));
    J2=J2-scl+1;
    J1=-J1;
elseif(a>180 && a<=270)
    scl=min(min(J1));
    J1=J1-scl+1;
    J2=-J2;
else
     scl=min(min(J2));
     J2=J2-scl+1;
end
for i=1:m;
    for j=1:n;
        K(J1(i,j),J2(i,j))=J(i,j);
    end
end
figure,imshow(K);
[m,n]=size(K);
J1(m+2,n+2)=0;
J2(m,n)=0;
for i=1:m+2;
    for j=1:n+2;
        if(i>1 && i<m+2)
            if(j>1 && j<n+2)
                J1(i,j)=K(i-1,j-1);
            end
        end
    end
end
for i=2:m+1;
    for j=2:n+1;
        w(1,10)=0;x=0;
        for k=-1:1;
            for l=-1:1;
                x=x+1;
                w(1,x)=J1(i+k,j+l);             
            end
        end
        for o=1:9;
            for x=1:9;
                if(w(1,x)<w(1,1+x))
                    temp=w(1,x);
                    w(1,x)=w(1,1+x);
                    w(1,1+x)=temp;
                end
            end
        end
        J2(i-1,j-1)=w(1,5);
    end
end
J3=uint8(J2);
figure,imshow(J3);
            