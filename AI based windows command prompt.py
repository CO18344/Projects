import pandas as pd
from os import *
list_of_cmds=['cd','date','mkdir','shutdown /s','rd','exit','python','compile','cls','control panel','cmd']

frame=pd.read_excel('C:\\Users\\SATVIK\\Desktop\\project.xlsx')
data=frame.loc[:,'dataset']
l=[]

for x in data:
    l.append(x.split(','))

i=0
d={0:{},1:{},2:{},3:{},4:{},5:{},6:{},7:{},8:{},9:{},10:{}}
all_words=[]

count_cat=[]
for x in l:
    each_cat=[]
    for y in x:
        all_words=all_words+y.split()
        each_cat+=y.split()
    #each_cat=list(set(each_cat))
    count_cat.append(len(each_cat))
    set_type=list(set(each_cat))
    for z in set_type:
        d[i][z]=each_cat.count(z)
    i=i+1
Prob_list=[]
alpha=1     
unique_words=list(set(all_words))
unique_words.sort()
#print(count_cat)
D=len(unique_words)
cont=1
while cont==1:
    
    a=input(getcwd()+'>>>')
    y=a.lower()
    li=y.split()
    li=list(set(li))
    for item in range(len(list_of_cmds)):
        for x in li:
            if(d[item].get(x)==None):
                xi=0
            else:
                xi=d[item].get(x)
            N=count_cat[item]
            term=(xi+alpha)/(N+alpha*D)
            Prob_list.append(term)
            #print(xi,alpha,N,alpha*D)        
    res=[]
    var=1
    #print((Prob_list))
    i=0
    for x in range(len(list_of_cmds)):
        var=1
        for y in range(len(li)):
        
            var=var* Prob_list[len(li)*i:(i+1)*len(li)][y]
        
        res.append(var)
        i=i+1
    
    #print(max(res))  
    ind=res.index(max(res))
    #print('Command = ',list_of_cmds[ind])
    if a=='':
        print()
        
    elif list_of_cmds[ind]=='cd':
        print('Enter the name of directory : ',end='')
        folder=input()
        chdir(folder)
    elif list_of_cmds[ind]=='exit':
        cont=0
        system('exit')
    elif list_of_cmds[ind]=='mkdir' or list_of_cmds[ind]=='rd':
        print('Enter name of directory: ',end='')
        folder=input()
        system(list_of_cmds[ind]+' '+ folder)
    elif list_of_cmds[ind]=='python':
        system('python')
    elif list_of_cmds[ind]=='compile':
        print('Enter name of file: ',end='')
        file=input()
        print(file)
        boolean='.cpp' in file
        boolean1='.py' in file
        if boolean == True:
            
            system('g++ {} -o run.exe'.format(file))
            system('run.exe')
        elif boolean1== True:
            
            system('python {}'.format(file))
        
    else:
        system(list_of_cmds[ind])
    
        

    Prob_list=[]
    
    #system('mkdir ppp')
