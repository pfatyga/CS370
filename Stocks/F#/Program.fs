open System;

[<EntryPoint>]
let main argv = 
    let test_cases = Console.ReadLine() |> Int32.Parse
    for t in 0 .. test_cases-1 do
        let N = Console.ReadLine() |> Int32.Parse
    
        let prices = Console.ReadLine().Split(' ') |> Array.map (fun s -> s |> Int64.Parse)

        let next_max = Array.create (N+1) -1L

        for i in (N-1) .. -1 .. 0 do
            Array.set next_max i (max prices.[i] next_max.[i+1])    //construct next_max array

        next_max.[1..] 
            |> Seq.map2 (fun prices next_max -> (prices,next_max)) prices  //put the prices and the next_max array starting at index 1 together into a tuple
            |> Seq.fold(fun acc elem -> 
                            let price = elem |> fst
                            let max = elem |> snd
                            let num_stocks = acc |> fst
                            let profit = acc |> snd
                            if price < max then
                                (num_stocks+1L, profit-price)
                            elif price > max then
                                (0L, profit+num_stocks*price)
                            else
                                acc) (0L,0L)
            |> snd
            |> printf "%i\n"

    0 // return an integer exit code
