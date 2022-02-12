i=1
for OUTPUT in $(seq 10)
do
    echo $i
    make run < testcases/Testcases/input/$i.in | colordiff testcases/Testcases/output/$i.out -
    let i++
done

echo $i
    make run < testcases/sample\ testcases/sample.in | colordiff testcases/sample\ testcases/sample.out -
