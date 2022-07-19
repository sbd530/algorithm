package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)

func main() {
	defer wr.Flush()
	// sc.Split(bufio.ScanWords)

	sc.Scan()
	text := sc.Text()

	fmt.Fprintln(wr, text+"??!")
}
