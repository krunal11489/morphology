%clear;close all;
function [se]=stlm
x=input('1:diomond,2:rectangle,3:square:,4:disk==');
if(x==1)
%     y=input('enter size of strucuring element:');
%     for i=1:2*y+1;
%         for j=1:2*y+1;
%             if(i<=y+1)
%                 if(j>=y+2-i && j<=i+y)
%                     se(i,j)=true;
%                 else
%                     se(i,j)=false;
%                 end
%             else
%                 if(j>=i-y && j<=3*y+2-i)
%                     se(i,j)=true;
%                 else
%                     se(i,j)=false;
%                 end
%             end
%         end
%     end
y=input('enter diomond size:');
for i=1:2*y+1;
    for j=1:2*y+1;
        temp=abs(y+1-i)+abs(y+1-j);
        if(temp<=y)
             se(i,j)=true;
        else
             se(i,j)=false;
        end
    end
end
elseif(x==2)
    y=input('enter no. of rows of strucuring element:');
    z=input('enter no. of columns of strucuring element:');
    se=true(y,z);
elseif(x==3)
    y=input('enter no. of rows/columns of strucuring element:');
    se=true(y,y);
elseif(x==4)
    y=input('enter disk radius:');
for i=1:2*y+1;
    for j=1:2*y+1;
        temp=sqrt((y+1-i)*(y+1-i)+(y+1-j)*(y+1-j));
        if(temp<=y)
             se(i,j)=true;
        else
             se(i,j)=false;
        end
    end
end
end
end

        