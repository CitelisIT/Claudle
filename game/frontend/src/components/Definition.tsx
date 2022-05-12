import React, { useContext } from "react";
import { SettingsContext } from "../App";

interface Props {
  target: string;
}

export default function DefinitionLink({ target }: Props) {
  const settingsContext = useContext(SettingsContext);
  const lang =
    settingsContext.lang === "english"
      ? "en"
      : settingsContext.lang === "fr"
      ? "fr"
      : "cloclo";
  return (
    <button
      className="p-2 mt-12 mr-8 text-sm border rounded-lg text-amber-400 border-amber-400 w-max md:text-lg lg:text-xl"
      onClick={() =>
        window.open(
          lang === "fr"
            ? "https://www.cnrtl.fr/definition/" + target
            : lang === "en"
            ? "https://dictionary.cambridge.org/dictionary/english/" + target
            : "https://www.youtube.com/watch?v=" + target,
          "_blank"
        )
      }
    >
      Définition
    </button>
  );
}
