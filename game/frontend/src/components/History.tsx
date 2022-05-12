import { CheckIcon, XIcon } from "@heroicons/react/outline";
import axios from "axios";
import { useEffect, useState } from "react";
import { getCookie } from "../utils/utils";
import HistoryPopup from "./HistoryPopup";

type HistoryElement = {
  listWord: string[][];
  target: string;
  hints: number[][];
  status: string;
};

export default function History() {
  const [history, setHistory] = useState<Array<HistoryElement>>([
    {
      listWord: [[""]],
      target: "",
      hints: [[0]],
      status: "",
    },
  ]);
  const [ready, setReady] = useState(false);
  useEffect(() => {
    axios
      .get("/api/history", {
        withCredentials: true,
        headers: {
          "X-CSRF-Token": getCookie("csrf_access_token")!,
        },
      })
      .then((response) => {
        setHistory(response.data.histo);
        let _popupState = [];
        for (let i = 0; i++; i < response.data.length) {
          _popupState.push(false);
        }
        setHistoOpen(_popupState);
        setReady(true);
      });
  }, []);
  const [histoOpen, setHistoOpen] = useState<boolean[]>([false]);

  function togglePopup(index: number, state: boolean) {
    let _openState = histoOpen;
    _openState[index] = true;
    setHistoOpen(_openState);
  }

  return ready ? (
    <ul className="w-full">
      {history.map((game, index) => (
        <li
          className={`flex items-center justify-between text-xl w-full text-gray-200 border p-4 border-gray-800 rounded-lg ${
            game.status === "Victoire" ? "bg-green-600 " : " bg-red-600"
          }`}
          key={game.target}
        >
          <div className="flex items-center justify-center gap-4">
            {game.status === "Victoire" ? (
              <CheckIcon className="w-8 h-8" />
            ) : (
              <XIcon className="w-8 h-8" />
            )}
            <span>{game.status}</span>
          </div>
          <div>{game.target.toUpperCase()}</div>

          <HistoryPopup
            listWord={game.listWord}
            hints={game.hints}
            target={game.target}
            togglePopup={(state: boolean) => togglePopup(index, state)}
          />
        </li>
      ))}
    </ul>
  ) : (
    <></>
  );
}
