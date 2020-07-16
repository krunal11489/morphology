function gen_file(I,filename)
fid=fopen(filename,'w+');
if(-1==fid)
    error(['failed to open' filename]);
end
fprintf(fid,'unsigned int ipimage[65536]={\n'); 	% evertime it display 32bit in new line
[M,N]=size(I);
I=double(I);
for ii=M:-1:1
    for jj=1:N/4
        fprintf(fid,'0x%0.2x%0.2x%0.2x%0.2x,\n',I(ii,4*jj:-1:4*(jj-1)+1));
    end
end	
fprintf(fid,'};\n');
fclose(fid);
end
