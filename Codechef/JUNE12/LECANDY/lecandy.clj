(defn read-ints [s]
  (map #(Integer/parseInt %) (clojure.string/split s #"\s")))

(defn solve-case [n c a]
  (if (> c (reduce + a))
    "Yes"
    "No"))

(defn read-input []
  (let [lines (line-seq (java.io.BufferedReader. *in*))
        t (Integer/parseInt (first lines))]
   (loop [cur-case 1 lines (rest lines)]
     (let [[n c] (read-ints (first lines))
           a (read-ints (second lines))
           result (solve-case n c a)]
       (println result)
       (when (< cur-case t)
         (recur (inc cur-case) (drop 2 lines)))))))

(read-input)
