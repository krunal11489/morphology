function[J]=k_dil(I,se,k)
J=I;
for i=1:k
    J=dil_m(J,se);
end
end